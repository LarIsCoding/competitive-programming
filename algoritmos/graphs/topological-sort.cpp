#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define UNVISITED 2
#define PROCESSING 3
#define VISITED 1

vi dfs_num;
vector<vii> adj;
vi topoSort;

void dfs(int u) {
    dfs_num[u] = VISITED;
    for(int j = 0; j < (int) adj[u].size(); j++) {
        ii v = adj[u][j];
        if(dfs_num[v.first] == UNVISITED)
            dfs(v.first);
    } 
    topoSort.push_back(u);
}

// checa se é possivel
bool dfs2(int u) {
    dfs_num[u] = PROCESSING;
    for(int j = 0; j < (int) adj[u].size(); j++) {
        int v = adj[u][j];
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
    int v;
    dfs_num.assign(v, UNVISITED);
    topoSort.clear();

    for(int i = 0; i < v; i ++) {
        if(dfs_num[i] == UNVISITED) {
            dfs(i);
        }
    }

    reverse(topoSort.begin(), topoSort.end());

    return 0;
}