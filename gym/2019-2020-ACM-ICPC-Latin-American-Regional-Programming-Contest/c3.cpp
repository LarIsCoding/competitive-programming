#include <iostream>
#include <vector>
#include <cstring>

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

const int MAXN=(int)1e5+5;
const int K = 18;

ii f[2][K + 1][MAXN];

vi v, h;

struct Node {
    int func, min, max;
};

class SegmentTree {

    private:
    vector<ii> st;
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
            st[p] = mp(A[L],0);
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        ii p1 = st[left(p)];
        ii p2 = st[right(p)];

        st[p] = mp(p1.f+p1.s,+p2.f+p2.s);
    }

    ii rmq(int p, int L, int R, int i, int j, int l, int u) {
        if(i > R || j < L) return mp(-1,0);

        if(L == R) {
            if(st[p].f<l) return mp(L,0);
            if(st[p].f>u) return mp(L,1);
            return mp(-1,0);
        }

        if(L >= i && R <= j) {
            if(st[p].f<l||st[p].f>u) return rmq(left(p), L, (L + R)/2, i, j, l, u);
            return rmq(right(p), (L + R)/2 + 1, R, i, j, l, u);
        }

        ii p1 = rmq(left(p), L, (L + R)/2, i, j, l, u);
        ii p2 = rmq(right(p), (L + R)/2 + 1, R, i, j, l, u);

        if(p1.f == -1) return p2;
        return p1;
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.resize(4 * n);
        build(1, 0, n - 1);
    }

    ii rmq(int i, int j, int l, int u) {
        // cout<<l<<' '<<u<<endl;
        return rmq(1, 0, n - 1, i, j, l, u);
    }
};

int func(ii type1, ii type2) {

}

// int performQuery(int L, int R) {
//     long long sum = 0;
//     for (int i = K; i >= 0; i--) {
//         if ((1 << i) <= R - L + 1) {
//             sum += st[i][L];
//             L += 1 << i;
//         }
//     }
// }

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,l,u;
    cin >> n>>l>>u;

    v.resize(n);
    h.resize(n);

    int acc=0;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        acc+=v[i];
        h[i]=acc;
        cout<<h[i]<<' ';
    }
    cout<<endl;

    SegmentTree st(v);

    for (int j = 0; j + (1 << 0) <= n; j++) {
        f[0][0][j] = st.rmq(j+1,n-1,0,u-l);
        f[1][0][j] = st.rmq(j+1,n-1,l-u,0);
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            ii ov1 = f[0][i - 1][j];
            if(ov1.first==-1) {
                f[0][i][j] = mp(-1, 0);
            } else {
                ii ov2 = f[ov1.second][i - 1][j + (1 << (i - 1))];
                f[0][i][j] = mp(ov1.first+ov2.first, ov2.second);   
            }

            ov1 = f[1][i - 1][j];
            if(ov1.first==-1) {
                f[1][i][j] = mp(-1, 0);
            } else {
                ii ov2 = f[ov1.second][i - 1][j + (1 << (i - 1))];
                f[1][i][j] = mp(ov1.first+ov2.first, ov2.second);   
            }
        }
    }

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            cout<<f[0][i][j].first<<' ';
        }
        cout<<endl;
    }

    int q;cin>>q;

    for(int i=0;i<q;i++) {
        int left,right,x;cin>>left>>right>>x;
        // ii id = st.rmq(left-1,right-1,l-x,u-x);
        // cout<<id.f<<' '<<id.s<<endl;

    }

    return 0;
}