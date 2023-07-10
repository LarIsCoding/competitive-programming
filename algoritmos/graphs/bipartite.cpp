#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int s = 0;
vi color;
vector<vii> AdjList;

int main() {
    int v;
    queue<int> q; q.push(s);
    color.assign(v, INF);
    color[s] = 0;

    bool isBipartite = true;

    while(!q.empty() && isBipartite) {
        int u = q.front(); q.pop();
        for(int j = 0; j < AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if(color[v.first] == INF) {
                color[v.first] = 1 - color[u];
                q.push(v.first);
            } else if(color[v.first] == color[u]){
                isBipartite = false;
                break;
            }
        }
    }

    return 0;
}