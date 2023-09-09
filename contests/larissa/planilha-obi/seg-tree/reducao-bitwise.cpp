#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

struct Value {
    bool isValid;
    int idMin;
    int idMax;
    int orr;
    int andd;
    int xorr;
};

class SegmentTree {

    private:
    vector<Value> st; vi A; // st -> indice do menor valor; A -> vetor com valores
    int n;

    int left(int p) {
        return p << 1;
    }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if(L == R) {
            st[p]=(Value){true,L,L,A[L],A[L],A[L]};
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        int idMenor = A[p1.idMin] < A[p2.idMin] ? p1.idMin : p2.idMin;
        int idMaior = A[p1.idMax] > A[p2.idMax] ? p1.idMax : p2.idMax;

        st[p]={true,idMenor,idMaior,p1.orr|p2.orr,p1.andd&p2.andd,p1.xorr^p2.xorr};
    }

    Value rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return (Value){false,0,0,0,0,0};
        if(L >= i && R <= j) return st[p];

        Value p1 = rmq(left(p), L, (L + R)/2, i, j);
        Value p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(!p1.isValid) return p2;
        if(!p2.isValid) return p1;
        
        int idMenor = A[p1.idMin] < A[p2.idMin] ? p1.idMin : p2.idMin;
        int idMaior = A[p1.idMax] > A[p2.idMax] ? p1.idMax : p2.idMax;

        return {true,idMenor,idMaior,p1.orr|p2.orr,p1.andd&p2.andd,p1.xorr^p2.xorr};
    }

    void update(int p, int L, int R, int i, int v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            A[L] = v;
            st[p]=(Value){true,L,L,A[L],A[L],A[L]};
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        int idMenor = A[p1.idMin] < A[p2.idMin] ? p1.idMin : p2.idMin;
        int idMaior = A[p1.idMax] > A[p2.idMax] ? p1.idMax : p2.idMax;

        st[p]={true,idMenor,idMaior,p1.orr|p2.orr,p1.andd&p2.andd,p1.xorr^p2.xorr};
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, {true});
        build(1, 0, n - 1);
    }

    void update(int i, int v) {
        update(1, 0, n - 1, i, v);
    }

    int orr(int i, int j) {
        Value res = rmq(1, 0, n - 1, i, j);
        Value s1 = rmq(1, 0, n - 1, i, res.idMax-1);
        Value s2 = rmq(1, 0, n - 1, res.idMax+1, j);
        int orRes = s1.isValid ? s1.orr : s2.orr;
        if(s2.isValid) orRes |= s2.orr;
        if(orRes == A[res.idMax]) return A[res.idMax];
        return -1;
    }

    int andd(int i, int j) {
        Value res = rmq(1, 0, n - 1, i, j);
        Value s1 = rmq(1, 0, n - 1, i, res.idMin-1);
        Value s2 = rmq(1, 0, n - 1, res.idMin+1, j);
        int andRes = s1.isValid ? s1.andd : s2.andd;
        if(s2.isValid) andRes &= s2.andd;
        if(andRes == A[res.idMin]) return A[res.idMin];
        return -1;
    }

    int xorr(int i, int j) {
        Value res = rmq(1, 0, n - 1, i, j);
        if(res.xorr == 0) return A[res.idMax];
        return -1;
    }
};

vi v;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin >> n >> q;

    v.assign(n,0);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    SegmentTree st(v);

    while(q--) {
        char op; int l, r;cin>>op>>l>>r;
        if(op=='x') {
            cout << st.xorr(l-1,r-1) << endl;
        } else if(op=='a') {
            cout << st.andd(l-1,r-1) << endl;
        } else if(op=='o') {
            cout << st.orr(l-1,r-1) << endl;
        } else {
            st.update(l-1,r);
        }
    }

    return 0;
}