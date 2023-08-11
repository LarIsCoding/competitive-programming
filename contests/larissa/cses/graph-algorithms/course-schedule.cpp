#include <iostream>
#include <vector>
#include <algorithm>

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

#define UNVISITED 2
#define PROCESSING 3
#define VISITED 1

vi dfs_num;
vector<vi> AdjList;
vi topoSort;

bool dfs(int u) {
    dfs_num[u] = PROCESSING;
    for(int j = 0; j < (int) AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if(dfs_num[v] == UNVISITED)
            dfs(v);
        if(dfs_num[v] == PROCESSING)
            return false;
    } 
    dfs_num[u] = VISITED;
    topoSort.push_back(u);
    return true;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    AdjList.resize(n);

    for(int i=0;i<m;i++) {
        int a,b;cin>>a>>b;a--;b--;
        AdjList[a].push_back(b);
    }

    dfs_num.assign(n, UNVISITED);
    topoSort.clear();

    for(int i = 0; i < n; i ++) {
        if(dfs_num[i] == UNVISITED) {
            if(!dfs(i)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    reverse(topoSort.begin(), topoSort.end());

    for(int i=0;i<n;i++) {
        cout << topoSort[i]+1;
        if(i < n-1) cout << ' ';
    }
    cout << endl;

    return 0;
}