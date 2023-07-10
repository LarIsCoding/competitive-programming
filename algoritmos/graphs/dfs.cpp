#include <vector>

using namespace std;

#define UNVISITED 2
#define VISITED 1

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dfs_num;
vector<vii> AdjList;

void dfs (int u) {
    dfs_num[u] = VISITED;
    for(int j = 0; j < (int) AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if(dfs_num[v.first] == UNVISITED)
            dfs(v.first);
    } 
}

int main() {
    int numCC = 0;
    int v;
    dfs_num.assign(v, UNVISITED);

    for(int i = 0; i < v; i ++) {
        if(dfs_num[i] == UNVISITED) {
            numCC++;
            dfs(i);
        }
    }

    return 0;
}