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

        st[p] = p1 ^ p2;
    }

    int rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L + R)/2, i, j);
        int p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return p1 ^ p2;
    }

    void update(int p, int L, int R, int i, int v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            st[p] = L;
            A[L] = v;
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        st[p] = (A[p1] <= A[p2]) ? p1 : p2;
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

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;cin>>n;

        vi a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        int xor0=0,xor1=0;

        for(int i=0;i<n;i++) {
            char aux;cin>>aux;
            if(aux=='0') xor0^=a[i];
            else xor1^=a[i];
        }

        SegmentTree st(a);

        int q;cin>>q;
        int space=false;
        while(q--){
            int op;cin>>op;

            if(op==1) {
                int l,r;cin>>l>>r;l--;r--;
                xor0^=st.rmq(l,r);
                xor1^=st.rmq(l,r);
            } else {
                int b;cin>>b;
                if(space) cout<<' ';
                space=true;
                if(b==0) cout<<xor0;
                else cout<<xor1;
            }
        }
        cout<<endl;
    }

    return 0;
}