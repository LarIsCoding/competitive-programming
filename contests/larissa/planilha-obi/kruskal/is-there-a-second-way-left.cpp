#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const ll inf = (int)1e12;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

class UnionFind {

    private:
    vi p, rank, setSize;
    int numSets;

    public:
    UnionFind(int N) {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++) 
            p[i] = i;
    }

    int findSet(int i) {
        if(p[i] == i) return i;
        return p[i] = findSet(p[i]);
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if(isSameSet(i, j)) return;

        numSets--;
        int x = findSet(i);
        int y = findSet(j);

        if(rank[x] > rank[y]) {
            p[y] = x;
            setSize[x] += setSize[y];
        } else {
            p[x] = y;
            setSize[y] += setSize[x];
        }

        if(rank[x] == rank[y]) rank[y]++;
    }

    int numDisjointSets() {
        return numSets;
    }

    int sizeOfSets(int i) {
        return setSize[findSet(i)];
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
    bool operator==(Edge const& other) {
        return u == other.u && v == other.v;
    }
};

bool cmp(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}

vector<Edge> edges;
vector<ii> adj[105];
bool visited[105];

int getMaxEdgeInPath(int u, int v) {
    if(visited[u]) return -1;
    visited[u]=true;
    if(u==v) return 0;
    for(auto it : adj[u]) {
        int r = getMaxEdgeInPath(it.first, v);
        if(r != -1) {
            return max(r, it.second);
        }
    }
    return -1;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int c = 1; c <= t;c++) {
        int n, m; cin>>n>>m;
        edges.clear();
        UnionFind uf(n);

        for(int i =0;i<m;i++) {
            int u,v,c;cin>>u>>v>>c;u--;v--;
            edges.push_back((Edge){u,v,c});
        }

        sort(edges.begin(), edges.end(), cmp);
        
        for(int i=0;i<105;i++) {
            adj[i].clear();
        }
        vector<Edge> notUsed;
        ll cost = 0;
        for(Edge e : edges) {
            if(!uf.isSameSet(e.u, e.v)) {
                adj[e.u].push_back(mp(e.v, e.weight));
                adj[e.v].push_back(mp(e.u, e.weight));
                uf.unionSet(e.u, e.v);
                cost += (ll)e.weight;
            } else {
                notUsed.push_back(e);
            }
        }

        if(uf.numDisjointSets() > 1) {
            cout << "Case #" << c << " : No way\n";
            continue;
        }

        ll minCost = inf;
        for(Edge e : notUsed) {
            for(int i=0;i<105;i++) {
                visited[i]=false;
            }
            ll maxCost = getMaxEdgeInPath(e.u, e.v);
            minCost = min(minCost, cost-maxCost+(ll)e.weight);
        }

        if(minCost == inf) {
            cout << "Case #" << c << " : No second way\n";
        } else {
            cout << "Case #" << c << " : " << minCost << endl;
        }
    }

    return 0;
}