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

vi cartas[50005];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        int num;cin>>num;
        cartas[num].push_back(i);
    }

    for(int i=0;i<n-1;i++) {
        int u,w;cin>>u>>w;
        v[u].push_back(w);
        v[w].push_back(u);
    }

    dist[1]=0;
    dfs(1,1);

    int acc=0;
    for(int i=1;i<=n/2;i++) {
        int u=cartas[i][0];
        int w=cartas[i][1];
        int l = lca(u, w);
        acc+= (dist[u]-dist[l]) + (dist[w]-dist[l]);
    }

    cout << acc << endl;

    return 0;
}