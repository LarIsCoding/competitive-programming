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

    int n,m;cin>>n>>m;

    while(n!=0||m!=0) {
        vector<Edge> edges;
        UnionFind uf(n);

        ll total = 0;
        for(int i=0;i<m;i++) {
            int u,v,c;cin>>u>>v>>c;
            edges.push_back((Edge){u,v,c});
            total+=(ll)c;
        }

        sort(edges.begin(), edges.end(), cmp);

        ll cost = 0;
        for(Edge e : edges) {
            if(!uf.isSameSet(e.u, e.v)) {
                cost += (ll)e.weight;
                uf.unionSet(e.u, e.v);
            }
        }

        cout << total-cost<<endl;

        cin>>n>>m;
    }

    return 0;
}