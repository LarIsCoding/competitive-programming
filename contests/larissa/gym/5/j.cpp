#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

vi adj[(int)1e5+5];
int visited[(int)1e5+5];
bool ciclo[(int)1e5+5];
set<int> cicloAtual;

bool dfs(int u, int p, int time) {
    if(visited[u]) {
        cicloAtual.insert(u);
        return;
    }
    visited[u]=time;

    for(int v : adj[u]) {
        if(v==p) continue;
        dfs(v,u,time+1);
    }

    if(!cicloAtual.empty()) {
        ciclo[u]=true;
    }
    if(cicloAtual.find(u)!=cicloAtual.end()) cicloAtual.erase(u);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,q;
    cin >> n>>m>>q;

    for(int i=0;i<m;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(visited,-1,sizeof visited);
    memset(ciclo,false,sizeof ciclo);

    dfs(1,0,0);

    for(int i=1;i<=n;i++) {
        cout <<ciclo[i]<< ' ';
    }cout <<endl;

    for(int i=0;i<q;i++) {
        int s,e;cin>>s>>e;
        if((!ciclo[s])&&(!ciclo[e])) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}