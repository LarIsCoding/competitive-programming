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

        vector<Edge> result;
        int cost=0;
        for(Edge e : edges) {
            if(!uf.isSameSet(e.u, e.v)) {
                cost += (ll)e.weight;
                result.push_back(e);
                uf.unionSet(e.u, e.v);
            }
        }

        ll minCost = inf;
        for(Edge r : result) {
            UnionFind uf2(n);
            ll cost2 = 0;
            for(Edge e : edges) {
                if(r == e) continue;
                if(!uf2.isSameSet(e.u, e.v)) {
                    cost2 += (ll)e.weight;
                    uf2.unionSet(e.u, e.v);
                }
            }
            if(uf2.numDisjointSets()==1) {
                minCost=min(minCost,cost2);
            }
        }

        cout << cost << ' ' <<minCost<<endl;
    }

    return 0;
}