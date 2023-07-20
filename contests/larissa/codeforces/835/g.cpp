#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii;

vector<ii> adj[(int)1e5+5];
vi num[(int)1e5+5][2];
set<int> found;
bool visited[(int)1e5+5];

void dfs(int u, int v, int x) {
    visited[u] = true;
    for(auto it : adj[u]) {
        if(visited[it.first]) continue;
        int y = x^it.second;
        if(it.first == v) continue;
        found.insert(y);
        dfs(it.first, v, y);
    }
}

bool dfs_inv(int u, int x) {
    visited[u] = true;
    for(auto it : adj[u]) {
        if(visited[it.first]) continue;
        int y = x^it.second;
        if(found.find(y) != found.end()) return true;
        if(dfs_inv(it.first, y)) return true;
    }
    return false;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n,a,b;cin>>n>>a>>b;a--;b--;

        for(int i=0;i<(int)1e5+5;i++) {
            adj[i].clear();
        }
        found.clear();

        for(int i=0;i<n-1;i++) {
            int u,v,w;cin>>u>>v>>w;u--;v--;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        memset(visited, false, sizeof(visited));
        found.insert(0);
        dfs(a,b,0);
        memset(visited, false, sizeof(visited));

        if(dfs_inv(b,0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}