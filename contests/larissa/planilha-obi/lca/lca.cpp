#include <iostream>
#include <vector>

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
vi v[100005];

void dfs(int a,int p){
    timer++; tin[a]=timer; up[0][a]=p; dist[a]=1+dist[p];
    for(int i=1;i<22;i++) up[i][a]=up[i-1][up[i-1][a]];

    for(auto x : v[a]){
        if(x==p) continue;
        dfs(x,a);
    }

    timer++; tout[a]=timer;
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

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int k=1;k<=t;k++) {
        int n;cin>>n;

        for(int i=1;i<=n;i++) {
            v[i].clear();
        }

        for(int i=1;i<=n; i++) {
            int m;cin>>m;
            for(int j=0;j<m;j++) {
                int u;cin>>u;
                v[i].push_back(u);
                v[u].push_back(i);
            }
        }

        dfs(1,1);

        int q;cin>>q;
        cout << "Case " << k << ":\n";
        while(q--) {
            int u,w;cin>>u>>w;
            cout << lca(u,w) << endl;
        }
    }

    return 0;
}