#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi adj[(int)2e5+5];
int alice[(int)2e5+5];
int bob[(int)2e5+5];

int dfsAlice(int v, int p, int time) {
    alice[v]=time;
    for(int u:adj[v]) {
        if(u==p) continue;
        dfsAlice(u,v,time+1);
    }
}

int dfsBob(int v, int p, int time) {
    bob[v]=time;
    for(int u:adj[v]) {
        if(u==p) continue;
        dfsBob(u,v,time+1);
    }
}

int findAns(int v, int p) {
    int ans=0;
    if(bob[v] < alice[v]) ans=alice[v];

    for(int u:adj[v]) {
        if(u==p) continue;
        int r=findAns(u,v);
        ans=max(ans,r);
    }
    return ans;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,x;
    cin >> n>>x;

    for(int i=0;i<n-1;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfsAlice(1,0,0);
    dfsBob(x,0,0);

    cout<<findAns(x,0)*2<<endl;

    return 0;
}