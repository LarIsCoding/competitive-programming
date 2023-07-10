#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int s = 0;
vi d, p;
vector<vii> AdjList;

void printPath(int u) {
    if(u == s) {
        cout << s;
        return;
    }
    printPath(p[u]);
    cout << ' ' << u;
}

int main() {
    d[s] = 0;
    queue<int> q; q.push(s);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int j = 0; j < AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if(d[v.first] == INF) {
                d[v.first] = d[u] + 1;
                p[v.first] = u;
                q.push(v.first);
            }
        }
    }

    return 0;
}