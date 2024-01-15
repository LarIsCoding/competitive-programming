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

vi v;

struct Value {
    bool isXor;
    int value;
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
            st[p] = {true,A[L]};
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        int value = p1.isXor ? p1.value|p2.value : p1.value^p2.value;
        st[p] = {!p1.isXor, value};
    }

    Value rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return {false,-1};
        if(L >= i && R <= j) return st[p];

        Value p1 = rmq(left(p), L, (L + R)/2, i, j);
        Value p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1.value == -1) return p2;
        if(p2.value == -1) return p1;
        
        int value = p1.isXor ? p1.value|p2.value : p1.value^p2.value;
        return {!p1.isXor, value};
    }

    void update(int p, int L, int R, int i, int v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            A[L] = v;
            st[p] = {true,A[L]};
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        int value = p1.isXor ? p1.value|p2.value : p1.value^p2.value;
        st[p] = {!p1.isXor, value};
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, {true,0});
        build(1, 0, n - 1);
    }

    void update(int i, int v) {
        update(1, 0, n - 1, i, v);
    }

    int rmq(int i, int j) {
        return rmq(1, 0, n - 1, i, j).value;
    }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n>>m;

    int total=pow(2,n);

    v.assign(total,0);

    for(int i=0;i<total;i++) {
        cin>>v[i];
    }

    SegmentTree st(v);

    while(m--) {
        int p,b;cin>>p>>b;p--;
        st.update(p,b);
        cout << st.rmq(0,total-1) << endl;
    }

    return 0;
}