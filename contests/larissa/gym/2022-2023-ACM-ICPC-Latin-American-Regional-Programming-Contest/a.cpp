#include <iostream>
#include <vector>
#include <cstring>

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

int adj[1005][2];
vi inv[1005];

bool reach[1005][3];
bool visited[1005];

void dfs(int v, int i, int s) {
    if(visited[v]) return;
    visited[v]=true;
    if(v==s) return;
    reach[v][i]=true;

    for(auto it:inv[v]) {
        dfs(it,i,s);
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        adj[i][0]=a;
        adj[i][1]=b;
        inv[a].push_back(i);
        inv[b].push_back(i);
    }

    for(int i=1;i<=n;i++) {
        memset(reach,false,sizeof reach);
        memset(visited,false,sizeof visited);
        dfs(i,0,-1);

        memset(visited,false,sizeof visited);
        dfs(adj[i][0],1,i);

        memset(visited,false,sizeof visited);
        dfs(adj[i][1],2,i);

        bool fail=false;
        for(int j=1;j<=n;j++) {
            if(j==i) continue;
            if(reach[j][0]&&reach[j][1]&&reach[j][2]) {
                cout<<"Y";
                fail=true;
                break;
            }
        }

        if(!fail) {
            cout<<'N';
        }
    }
    cout<<endl;

    return 0;
}