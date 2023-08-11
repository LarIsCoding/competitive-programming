#include <iostream>
#include <vector>

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

vi d, x;
vector<ii> edges;

void dfs(int u) {
    if(d[u] != AdjList[u].size() + 1) return;
    int v = x[u];
    for(int it : AdjList[u]) {
        v ^= it;
    }
    AdjList[v].push_back(u);
    edges.push_back(mp(u,v));
    dfs_num[u]=VISITED;
    dfs(v);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;

    d.resize(v);
    x.resize(v);
    AdjList.resize(v);

    for(int i=0;i<v;i++) {
        cin>>d[i]>>x[i];
    }

    dfs_num.assign(v, UNVISITED);

    for(int i = 0; i < v; i++) {
        if(dfs_num[i] == UNVISITED) {
            dfs(i);
        }
    }

    cout << edges.size() << endl;
    for(ii p : edges) {
        cout << p.f << ' ' << p.s << endl;
    }

    return 0;
}