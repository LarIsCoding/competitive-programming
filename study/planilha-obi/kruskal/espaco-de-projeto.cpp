#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
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
};

bool cmp(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;

    vector<Edge> edges;
    vector<Edge> edges2;
    int n = 0;
    
    for(int i = 0;i<m;i++) {
        int u,v,w;cin>>u>>v>>w;
        n = max(n, max(u, v));
        u--;v--;
        edges.push_back((Edge){u, v, w});
        edges2.push_back((Edge){u, v, -w});
    }

    UnionFind uf(n);

    sort(edges.begin(), edges.end(), cmp);
    sort(edges2.begin(), edges2.end(), cmp);

    int minCost = 0;
    for(Edge e : edges) {
        if(!uf.isSameSet(e.u, e.v)) {
            minCost += e.weight;
            uf.unionSet(e.u, e.v);
        }
    }

    UnionFind uf2(n);
    int maxCost = 0;
    for(Edge e : edges2) {
        if(!uf2.isSameSet(e.u, e.v)) {
            maxCost -= e.weight;
            uf2.unionSet(e.u, e.v);
        }
    }

    cout << maxCost << endl << minCost << endl;

    return 0;
}