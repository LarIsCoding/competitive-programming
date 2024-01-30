#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

int comp[(int)1e5+5];
vector<int> adjComp[(int)1e5+5];
vector<vi> components;
set<int> ans;

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

    for (auto u : adj[v]) {
        if(comp[v]!=comp[u]) {
            adjComp[comp[v]].push_back(comp[u]);
        }
        if (!used[u])
            dfs3(u);
    }
}

void dfs4(int v) {
    if(used[v]) return;
    used[v]=true;

    if(adjComp[v].empty()) {
        for(int u:components[v]) ans.insert(u);
    }
    for(int u: adjComp[v] ) {
        dfs4(u);
    }
}

int main() {
    int n,m;cin>>n;
    while(n!=0) {
        cin>>m;

        adj.assign(n,vi());
        adj_rev.assign(n,vi());

        for(int i=0;i<n;i++) {
            adjComp[i].clear();
        }

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
        
        int id=0;
        for (auto v : order)
            if (!used[v]) {
                dfs2(v);

                for(int v:component) {
                    comp[v]=id;
                }
                components.push_back(component);


                component.clear();
                id++;
            }
        
        used.assign(n, false);
        for(auto v : order) {
            if(!used[v])
                dfs3(v);
        }

        used.assign(n, false);
        for(auto v : order) {
            if(!used[comp[v]])
                dfs4(comp[v]);
        }
        
        bool space=false;
        for(int v:ans) {
            if(space) cout<<' ';space=true;
            cout<<v+1;
        }
        cout<<endl;

        ans.clear();
        components.clear();
        order.clear();

        cin>>n;
    }

    return 0;
}
