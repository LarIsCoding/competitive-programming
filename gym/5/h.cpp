#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

vi adj[(int)1e6+5];
int g[(int)1e6+5];
int r[(int)1e6+5];

map<int,int> m;

void dfs(int i) {
    bool existe=true;
    if(m.find(g[i])==m.end()) existe=false;
    
    if(!existe) m[g[i]]=1;
    else m[g[i]]++;

    r[i]=m.size();
    for(int f : adj[i]) {
        dfs(f);
    }

    if(!existe) m.erase(g[i]);
    else m[g[i]]--;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        int aux;cin>>aux;
        adj[aux].push_back(i);
    }

    for(int i=1;i<=n;i++) {
        int aux;cin>>aux;
        g[i]=aux;
    }

    memset(r,0,sizeof r);

    dfs(adj[0][0]);

    bool espaco=false;
    for(int i=1;i<=n;i++) {
        if(espaco)cout << ' ';
        cout << r[i];
        espaco=true;
    }
    cout <<endl;

    return 0;
}