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
    int sum;
    int max;
    int min;
};

class SegmentTree {

    private:
    vi A; // st -> indice do menor valor; A -> vetor com valores
    vector<Value> st;
    int n;

    int left(int p) {
        return p << 1;
    }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if(L == R) {
            st[p] = {A[L],A[L],A[L]};
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        int sum=p1.sum+p2.sum;
        int ma=max(p1.max,p2.max);
        int mi=min(p1.min,p2.min);

        st[p] = {sum,ma,mi};
    }

    Value rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return {-1,-1,-1};
        if(L >= i && R <= j) return st[p];

        Value p1 = rmq(left(p), L, (L + R)/2, i, j);
        Value p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1.sum == -1) return p2;
        if(p2.sum == -1) return p1;
        
        int sum=p1.sum+p2.sum;
        int ma=max(p1.max,p2.max);
        int mi=min(p1.min,p2.min);

        return {sum,ma,mi};
    }

    void update(int p, int L, int R, int i, int v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            A[L] = v;
            st[p] = {A[L],A[L],A[L]};
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        int sum=p1.sum+p2.sum;
        int ma=max(p1.max,p2.max);
        int mi=min(p1.min,p2.min);

        st[p] = {sum,ma,mi};
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, {-1,-1,-1});
        build(1, 0, n - 1);
    }

    void update(int i, int v) {
        update(1, 0, n - 1, i, v);
    }

    int rmq(int i, int j) {
        Value r = rmq(1, 0, n - 1, i, j);
        return r.sum-r.max-r.min;
    }
};

vi v;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin >>n>>q;

    v.assign(n,0);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    SegmentTree st(v);

    while(q--) {
        int t;cin>>t;
        if(t==1) {
            int l,r;cin>>l>>r;l--;r--;
            cout << st.rmq(l,r) << endl;
        } else {
            int i,v;cin>>i>>v;i--;
            st.update(i,v);
        }
    }

    return 0;
}