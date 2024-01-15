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
    int maxDiff;
    int min;
    int max;
};

class SegmentTree {

    private:
    vector<Value> st;
    vi A; // st -> indice do menor valor; A -> vetor com valores
    int n;

    int left(int p) {
        return p << 1;
    }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if(L == R) {
            st[p] = {0,A[L],A[L]};
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        int maxDiff1 = max(p1.maxDiff, p2.maxDiff);
        int maxDiff2 = max(p1.max-p2.min, p2.max-p1.min);

        st[p] = {max(maxDiff1,maxDiff2),min(p1.min,p2.min),max(p1.max,p2.max)};
    }

    Value rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return {-1,-1,-1};
        if(L >= i && R <= j) return st[p];

        Value p1 = rmq(left(p), L, (L + R)/2, i, j);
        Value p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1.maxDiff == -1) return p2;
        if(p2.maxDiff == -1) return p1;
        
        int maxDiff1 = max(p1.maxDiff, p2.maxDiff);
        int maxDiff2 = max(p1.max-p2.min, p2.max-p1.min);

        return {max(maxDiff1,maxDiff2),min(p1.min,p2.min),max(p1.max,p2.max)};
    }

    void update(int p, int L, int R, int i, int v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            Value old = st[p];
            st[p] = {0,min(v,old.min),max(v,old.max)};
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        int maxDiff1 = max(p1.maxDiff, p2.maxDiff);
        int maxDiff2 = max(p1.max-p2.min, p2.max-p1.min);

        st[p] = {max(maxDiff1,maxDiff2),min(p1.min,p2.min),max(p1.max,p2.max)};
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, {0,0,0});
        build(1, 0, n - 1);
    }

    void update(int i, int v) {
        update(1, 0, n - 1, i, v);
    }

    int rmq(int i, int j) {
        return rmq(1, 0, n - 1, i, j).maxDiff;
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
        int op;cin>>op;

        if(op==1) {
            int p,i;cin>>p>>i;i--;
            st.update(i,p);
        } else {
            int l,r;cin>>l>>r;l--;r--;
            cout<<st.rmq(l,r)<<endl;
        }
    }

    return 0;
}