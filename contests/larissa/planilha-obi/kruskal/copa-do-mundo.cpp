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

    int n, f, r;
    cin>>n>>f>>r;

    vector<Edge> edgesF;

    for(int i=0;i<f;i++) {
        int u,v,c;cin>>u>>v>>c;
        u--;v--;
        edgesF.push_back((Edge){u,v,c});
    }

    vector<Edge> edgesR;
    for(int i=0;i<r;i++) {
        int u,v,c;cin>>u>>v>>c;
        u--;v--;
        edgesR.push_back((Edge){u,v,c});
    }

    sort(edgesF.begin(), edgesF.end(), cmp);
    sort(edgesR.begin(), edgesR.end(), cmp);

    int cost = 0;
    UnionFind uf(n);

    for(Edge e : edgesF) {
        if(!uf.isSameSet(e.u, e.v)) {
            cost += e.weight;
            uf.unionSet(e.u, e.v);
        }
    }

    for(Edge e : edgesR) {
        if(!uf.isSameSet(e.u, e.v)) {
            cost += e.weight;
            uf.unionSet(e.u, e.v);
        }
    }

    cout << cost << endl;

    return 0;
}