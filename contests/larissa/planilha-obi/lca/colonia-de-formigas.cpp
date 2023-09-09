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

int n, tin[200005], tout[200005], t, up[22][200005];
ll mup[22][200005];
vector<ii> v[200005];

void dfs(int a,int p,int w){
    tin[a]=t++; up[0][a]=p; mup[0][a]=w;
    
    for(int i=1;i<=20;i++) {
        up[i][a]=up[i-1][up[i-1][a]], mup[i][a]=mup[i-1][a]+mup[i-1][up[i-1][a]];
    }

    for(auto b : v[a]) if(b.f!=p) dfs(b.f,a,b.s);

    tout[a]=t++;
}

bool anc(int a,int b){
    return (tin[a]<=tin[b] && tout[b]<=tout[a]);
}

int lca(int a,int b){
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int i=20;i>=0;i--)
        if(!anc(up[i][a],b)) a=up[i][a];

    return up[0][a];
}

ll got(int a,int b){
    ll resp=0;
    
    for(int i=20;i>=0;i--)
        if(!anc(up[i][a],b)){ resp=resp+mup[i][a]; a=up[i][a];}

    return resp+mup[0][a];
}

ll getBig(int a,int b){
    if(a==b) return 0;
    int c=lca(a,b);
    if(c==a) return got(b,a);
    if(c==b) return got(a,b);

    return got(a,c)+got(b,c);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while(n != 0) {
        for(int i=0;i<n;i++) {
            v[i].clear();
        }

        for(int i=1;i<n;i++) {
            int u,d;cin>>u>>d;
            v[i].push_back(mp(u,d));
            v[u].push_back(mp(i,d));
        }

        dfs(0,0,0);

        int q;cin>>q;

        bool espaco=false;
        while(q--){
            int s,t;cin>>s>>t;
            ll res = getBig(s,t);
            if(espaco) cout << ' ';
            cout << res;
            espaco=true;
        }
        cout << endl;
        cin >> n;
    }

    return 0;
}