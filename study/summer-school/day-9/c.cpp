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

int v[505];
vector<set<int> > adj;
vector<set<int> > adj_rev;
int memo[505];

int dfs(int w, bool again) {
    if(memo[w]!=-1 && !again) return memo[w];
    int best=inf;
    for(int u:adj_rev[w]) {
        best=min(best,v[u]);
        best=min(best,dfs(u,false));
    }
    return memo[w] = best;
}

void printgraph(int n) {
    for(int i=1;i<=n;i++) {
        dbg(i);
        for(int j:adj_rev[i]) cout<<j<<' ';
        cout<<endl;
    }
}

void solve() {
    int n,m,q;

    while(cin>>n>>m>>q) {
        memset(memo,-1,sizeof memo);
        for(int i=1;i<=n;i++) {
            cin>>v[i];
        }

        adj.clear();
        adj_rev.clear();
        adj.resize(n+1);
        adj_rev.resize(n+1);

        for(int i=0;i<m;i++) {
            int a,b;
            cin>>a>>b;
            adj[a].insert(b);
            adj_rev[b].insert(a);
        }

        while(q--) {
            string c;cin>>c;

            if(c=="T") {
                int a,b;cin>>a>>b;

                for(int v:adj[a]) {
                    if(adj[b].find(v)!=adj[b].end()) continue;
                    if(v==b) continue;
                    adj_rev[v].erase(a);
                    adj_rev[v].insert(b);
                }
                for(int v:adj[b]) {
                    if(adj[a].find(v)!=adj[a].end()) continue;
                    if(v==a) continue;
                    adj_rev[v].erase(b);
                    adj_rev[v].insert(a);
                }
                swap(adj[a],adj[b]);
                if(adj[a].find(a)!=adj[a].end()) {
                    adj[a].erase(a);
                    adj[a].insert(b);
                }
                if(adj[b].find(b)!=adj[b].end()) {
                    adj[b].erase(b);
                    adj[b].insert(a);
                }

                for(int v:adj_rev[a]) {
                    if(adj_rev[b].find(v)!=adj_rev[b].end()) continue;
                    if(v==b) continue;
                    adj[v].erase(a);
                    adj[v].insert(b);
                }
                for(int v:adj_rev[b]) {
                    if(adj_rev[a].find(v)!=adj_rev[a].end()) continue;
                    if(v==a) continue;
                    adj[v].erase(b);
                    adj[v].insert(a);
                }
                swap(adj_rev[a],adj_rev[b]);
                if(adj_rev[a].find(a)!=adj_rev[a].end()) {
                    adj_rev[a].erase(a);
                    adj_rev[a].insert(b);
                }
                if(adj_rev[b].find(b)!=adj_rev[b].end()) {
                    adj_rev[b].erase(b);
                    adj_rev[b].insert(a);
                }

                if(adj[a].find(b)!=adj[a].end()) {
                    memo[a]=dfs(a,true);
                    memo[b]=dfs(b,true);
                } else {
                    memo[b]=dfs(b,true);
                    memo[a]=dfs(a,true);
                }
                // printgraph(n);
            } else {
                int e;cin>>e;
                // dbg(e);
                if(adj_rev[e].size()==0) {
                    cout<<"*\n";
                    continue;
                }
                cout<<dfs(e,false)<<endl;
            }
        }
    }
    
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