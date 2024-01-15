#include <iostream>
#include <vector>
#include <math.h>

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

int n, tin[100005], tout[100005], timer, up[22][100005], dist[100005];
vi v[100005], path;

void dfs(int a,int p){
    timer++; tin[a]=timer; up[0][a]=p; dist[a]=1+dist[p];
    for(int i=1;i<22;i++) up[i][a]=up[i-1][up[i-1][a]];
    path.push_back(a);

    for(auto x : v[a]){
        if(x==p) continue;
        dfs(x,a);
    }

    timer++; tout[a]=timer;
    path.push_back(a);
}

int anc(int a,int b){
    return (tin[a]<=tin[b] && tout[b]<=tout[a]);
}

int lca(int a,int b){
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int i=21;i>=0;i--)
        if(!anc(up[i][a],b)) a=up[i][a];

    return up[0][a];
}

int upK(int a,int b){
    for(int i=21;i>=0;i--)
        if(b>=(1<<i)) b-=(1<<i), a=up[i][a];

    return a;
}

int memo[(int)5e3+5][(int)1e3+5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,d;
    cin >>n>>d;

    for(int i=0;i<n-1;i++) {
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    timer=-1;
    dfs(1,1);

    int m;cin>>m;
    vector<ii> casas(m+1);
    for(int i=1;i<=m;i++) {
        int c,v;cin>>c>>v;
        casas[i]=mp(c,v);
    }

    vector<int> a(2*n,0);
    int len = (int) sqrt (2*n+ .0) + 1; // size of the block and the number of blocks
    vector<int> b(len,0);

    int q;cin>>q;
    for(int i=0;i<m;i++) {
        int x,y,lit;cin>>x>>y>>lit;
        if(tin[y]<tin[x]) {
            swap(x,y);
        }
        int l1,r1,l2,r2;
        if(anc(x,y)) {
            l1=tin[x];
            r1=tin[y];
            l2=1;
            r2=0;
        } else {
            int lc = tin[lca(x,y)];
            l1=tin[lc];
            r1=tin[x];
            l2=tin[lc];
            r2=tin[y];
            a[lc]-=lit;
        }
        for (int i=l1; i<=r1; )
            if (i % len == 0 && i + len - 1 <= r1) {
                // if the whole block starting at i belongs to [l, r]
                b[i / len]+=lit;
                i += len;
            }
            else {
                a[i]+=lit;
                ++i;
            }
        for (int i=l2; i<=r2; )
            if (i % len == 0 && i + len - 1 <= r2) {
                // if the whole block starting at i belongs to [l, r]
                b[i / len]+=lit;
                i += len;
            }
            else {
                a[i]+=lit;
                ++i;
            }
    }

    for(int i=0;i<=d;i++) {
        memo[0][i]=0;
    }
    for(int i=0;i<=m;i++) {
        memo[i][0]=0;
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=d;j++) {
            int price = casas[i].s;
            int in=tin[casas[i].f];
            int out=tout[casas[i].f];
            int litros = a[in]+b[in/len]-a[out]-b[out/len];
            if(price>j) {
                memo[i][j] = memo[i-1][j];
            } else {
                memo[i][j] = max(memo[i-1][j], memo[i-1][j-price]+litros);
            }
        }
    }

    cout << memo[m][d] << endl;

    return 0;
}