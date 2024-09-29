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
#define EPS 1e-9

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); }

// Min
class SegmentTree {

    private:
    vi st, A; // st -> indice do menor valor; A -> vetor com valores
    int n;

    int left(int p) {
        return p << 1;
    }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if(L == R) {
            st[p] = A[L];
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        st[p] = (p1 <= p2) ? p1 : p2;
    }

    int rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L + R)/2, i, j);
        int p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (p1 <= p2) ? p1 : p2;
    }

    void update(int p, int L, int R, int i, int v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            st[p] = v;
            A[L] = v;
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        st[p] = (p1 <= p2) ? p1 : p2;
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void update(int i, int v) {
        update(1, 0, n - 1, i, v);
    }

    int rmq(int i, int j) {
        return rmq(1, 0, n - 1, i, j);
    }
};

void solve() {
    int n,k;cin>>n>>k;
    vi a(n+1);
    vi b(n+1);
    map<int, int> id;
    for(int i=1;i<n+1;i++) {
        cin>>a[i];
        id[a[i]]=i;
    }
    for(int i=1;i<n+1;i++) {
        cin>>b[i];
    }
    vi s(n+1,inf);
    s[n]=0;
    a[0]=0;
    b[0]=k;
    SegmentTree st(s);
    for(int i=n-1;i>=0;i--) {
        int l=i+1;
        int m=a[i]+b[i];
        auto it=upper_bound(a.begin(),a.end(),m);
        it--;
        int r=id[*it];
        if(r<l) {
            st.update(i,inf);
            continue;
        }
        int min=st.rmq(l,r);
        if(min==inf) st.update(i,inf);
        else st.update(i,min+1);
    }
    int res=st.rmq(0,0);
    if(res==inf) cout<<-1<<endl;
    else cout<<res-1<<endl;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    //cin >> t;

    for(int i=0;i<t;i++) {
        solve();
    }

    return 0;
}