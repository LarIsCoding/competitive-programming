#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

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
    int u, v;
    double weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

bool cmp(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}

vector<Edge> edges;
vector<ii> pos;

double dist(ii a, ii b) {
    return sqrt((a.first - b.first)*(a.first - b.first)+(a.second - b.second)*(a.second - b.second));
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;cin>>n;
        edges.clear();
        pos.clear();
        UnionFind uf(n);

        for(int i=0;i<n;i++) {
            int x,y;cin>>x>>y;
            pos.push_back(mp(x,y));

            for(int j=0;j<i;j++) {
                edges.push_back((Edge){i, j, dist(mp(x, y), pos[j])});
            }
        }

        sort(edges.begin(), edges.end(), cmp);

        double cost = 0;
        vector<Edge> result;

        for(Edge e : edges) {
            if(!uf.isSameSet(e.u, e.v)) {
                cost += e.weight;
                result.push_back(e);
                uf.unionSet(e.u, e.v);
            }
        }

        cout << setprecision(2) << fixed << cost/(double)100 << endl;
    }

    return 0;
}