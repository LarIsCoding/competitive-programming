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
    bool valid;
    int max;
    int total;
    int maxIni;
    int maxFim;
};

class SegmentTree {

    private:
    vector<Value> st;vi A; // st -> indice do menor valor; A -> vetor com valores
    int n;

    int left(int p) {
        return p << 1;
    }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if(L == R) {
            st[p] = {true,A[L],A[L],max(A[L], 0),max(A[L], 0)};
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        int newMax = max(p1.max,p2.max);
        int join = p1.maxFim+p2.maxIni;
        if(join!=0) newMax=max(newMax,join);

        int newTotal=p1.total+p2.total;

        int newMaxIni=max(p1.maxIni,p1.total+p2.maxIni);
        int newMaxFim=max(p2.maxFim,p2.total+p1.maxFim);

        st[p] = {true,newMax,newTotal,newMaxIni,newMaxFim};
    }

    Value rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return {false,0,0,0,0};
        if(L >= i && R <= j) return st[p];

        Value p1 = rmq(left(p), L, (L + R)/2, i, j);
        Value p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(!p1.valid) return p2;
        if(!p2.valid) return p1;
        
        int newMax = max(p1.max,p2.max);
        int join = p1.maxFim+p2.maxIni;
        if(join!=0) newMax=max(newMax,join);

        int newTotal=p1.total+p2.total;

        int newMaxIni=max(p1.maxIni,p1.total+p2.maxIni);
        int newMaxFim=max(p2.maxFim,p2.total+p1.maxFim);

        return {true,newMax,newTotal,newMaxIni,newMaxFim};
    }

    void update(int p, int L, int R, int i, int v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            A[L] = v;
            st[p] = {true,A[L],A[L],max(A[L], 0),max(A[L], 0)};
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        int newMax = max(p1.max,p2.max);
        int join = p1.maxFim+p2.maxIni;
        if(join!=0) newMax=max(newMax,join);

        int newTotal=p1.total+p2.total;

        int newMaxIni=max(p1.maxIni,p1.total+p2.maxIni);
        int newMaxFim=max(p2.maxFim,p2.total+p1.maxFim);

        st[p] = {true,newMax,newTotal,newMaxIni,newMaxFim};
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, {true,0,0,0,0});
        build(1, 0, n - 1);
    }

    void update(int i, int v) {
        update(1, 0, n - 1, i, v);
    }

    int rmq(int i, int j) {
        return rmq(1, 0, n - 1, i, j).max;
    }
};

vi v;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    v.assign(n,0);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    SegmentTree st(v);

    int m;cin>>m;
    while(m--) {
        int op,x,y;cin>>op>>x>>y;
        if(op==0) {
            st.update(x-1,y);
        } else {
            cout<<st.rmq(x-1,y-1)<<endl;
        }
    }

    return 0;
}