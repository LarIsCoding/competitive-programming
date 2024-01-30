#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

vector<vi> G;
vb visited;
vi depth, subtree_size;
int max_depth;
set<int> not_used;

void dfs2(int v) {
    visited[v] = true;

    int cnt = 0;
    for (int u: G[v]) {
        if (!visited[u]) {
            cnt++;
            depth[u] = depth[v]+1;
            dfs2(u);
        }
    }

    if (cnt == 0) {
        auto it = not_used.lower_bound(depth[v]);
        int d = *it;
        not_used.erase(it);
        max_depth = max(max_depth, d);
    }
}

void dfs1(int v) {
    visited[v] = true;
    subtree_size[v] = 1;
    for (int u: G[v]) {
        if (!visited[u]) {
            dfs1(u);
            subtree_size[v] += subtree_size[u];
        }
    }
}

void solve(){
    int n;
    cin >> n;

    G.assign(n+1, vi());
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    visited.assign(n+1, false);
    subtree_size.assign(n+1, 0);
    dfs1(1);

    visited.assign(n+1, false);
    depth.assign(n+1, -1);
    visited[1] = true;
    int ans = 0;
    for (int child: G[1]) {
        not_used.clear();
        for (int i = 0; i <= subtree_size[child]; i++)
            not_used.insert(i);
        max_depth = depth[child] = 0;
        dfs2(child);
        ans = max(ans, max_depth);
    }
    cout << ans+1 << '\n';
}

int main() {
    int t=1;
    //cin>>t;
    for(int i = 0;i < t; i++){
        solve();
    }

    return 0;
}