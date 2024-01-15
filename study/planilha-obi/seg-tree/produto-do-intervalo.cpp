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

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

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
            st[p] = A[L]==0? 0 :A[L]/abs(A[L]);
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        st[p] = p1*p2;
    }

    int rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return -2;
        if(L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L + R)/2, i, j);
        int p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1 == -2) return p2;
        if(p2 == -2) return p1;
        return p1 * p2;
    }

    void update(int p, int L, int R, int i, int v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            A[L] = v;
            st[p] = A[L]==0? 0 :A[L]/abs(A[L]);
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        st[p] = p1 * p2;
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

vi x;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;

    while(cin>>n) {
        cin>>k;
        x.assign(n,0);

        for(int i=0;i<n;i++) {
            cin>>x[i];
        }

        SegmentTree st(x);

        while(k--) {
            char comando;cin>>comando;
            int i,j;cin>>i>>j;
            if(comando=='C'){
                st.update(i-1,j);
            } else {
                int r = st.rmq(i-1,j-1);
                if(r==0) cout << 0;
                else if(r==1) cout << '+';
                else cout << '-';
            }
        }
        cout<<endl;
    }

    return 0;
}