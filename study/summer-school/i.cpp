#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

vector<vector<int> > adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

void dfs3(int v) {
    used[v] = true;

    for (auto u : adj_rev[v]) {
        if (!used[u])
            dfs3(u);
    }
}

int main() {
    int n,m;cin>>n>>m;

    adj.assign(n,vi());
    adj_rev.assign(n,vi());

    for(int i=0;i<m;i++) {
        int a, b;cin>>a>>b;a--;b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());
    
    for (auto v : order)
        if (!used[v]) {
            component.clear();
            dfs2(v);
        }
    
    used.assign(n, false);
    dfs3(component[0]);

    bool allUsed=true;
    for(int i:used) {
        if(!i) {
            allUsed=false;
            break;
        }
    }

    if(!allUsed) {
        cout<<0<<endl;
        return 0;
    }

    sort(component.begin(),component.end());
    cout<<component.size()<<endl;
    bool space=false;
    for(int v:component) {
        if(space)cout<<' ';space=true;
        cout<<v+1;
    }
    cout<<endl;

    return 0;
}