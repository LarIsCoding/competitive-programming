#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int coins[(int)1e5+5];

vector<vector<int>> adj, adj_rev;
vector<bool> used, componentUsed;
vector<int> order, component;

int comp[(int)1e5+5];
ll compVal[(int)1e5+5];
vector<int> adjComp[(int)1e5+5];

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

ll dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    ll acc=coins[v];
    for (auto u : adj_rev[v])
        if (!used[u])
            acc+=dfs2(u);
    return acc;
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

ll memo[(int)1e5+5];
ll dfs4(int v) {
    if(memo[v]!=-1)return memo[v];
    ll acc=compVal[v];
    ll best=0;
    for(int u: adjComp[v] ) {
        best=max(best,dfs4(u));
    }
    return memo[v]=acc+best;
}

int main() {
    int n,m;cin>>n>>m;

    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }

    adj.resize(n);
    adj_rev.resize(n);

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
            ll val = dfs2(v);

            for(int v:component) {
                comp[v]=id;
            }
            compVal[id]=val;

            component.clear();
            id++;
        }
    
    used.assign(n, false);
    for(auto v : order) {
        if(!used[v])
            dfs3(v);
    }


    ll best=0;
    memset(memo,-1,sizeof memo);
    for(auto v : order) {
        best=max(best,dfs4(comp[v]));
    }
    cout<<best<<endl;

    return 0;
}
