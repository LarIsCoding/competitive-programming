#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

vector<pair<int, int>> adj[1005];
int bfs_i[10001][1005];
int bfs_j[10001][1005];

void solve(){
    int n,m,k;cin>>n>>m>>k;
    int a,b;cin>>a>>b;
    for(int i=0;i<m;i++) {
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(ii v:adj[a]) {
        if(v.second>k) continue;
        bfs_i[v.second][v.first]=a;
        bfs_j[v.second][v.first]=0;
    }

    for(int t=1;t<=k;t++) {
        for(int v=1;v<=n;v++) {
            if(bfs_i[t][v] == 0) continue;
            for(ii u:adj[v]) {
                if(u.second+t > k) continue;
                bfs_i[u.second+t][u.first]=v;
                bfs_j[u.second+t][u.first]=t;
            }
        }
    }

    if(bfs_i[k][b]==0) {
        cout<<"Impossible\n";
        return;
    }

    vector<int> st;
    st.push_back(b);
    int t=k;
    int v=b;
    while(t>0) {
        st.push_back(bfs_i[t][v]);
        int newt=bfs_j[t][v];
        v=bfs_i[t][v];
        t=newt;
    }
    reverse(st.begin(), st.end());

    for(int i:st) {
        cout<<i<<' ';
    }
    cout<<'\n';
}

int main() {
    
    int t=1;
    //cin>>t;
    for(int i = 0;i < t; i++){
        solve();
    }


    return 0;
}
