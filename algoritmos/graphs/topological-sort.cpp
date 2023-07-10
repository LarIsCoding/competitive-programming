#include <vector>

using namespace std;

#define UNVISITED 2
#define VISITED 1

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dfs_num;
vector<vii> AdjList;
vi topoSort;

void dfs(int u) {
    dfs_num[u] = VISITED;
    for(int j = 0; j < (int) AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if(dfs_num[v.first] == UNVISITED)
            dfs(v.first);
    } 
    topoSort.push_back(u);
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