#include <iostream>
#include <vector>
#include <algorithm>

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

int key[505][4];
vector<Edge> edges;

int dist(int a, int b) {
    return min(abs(a - b), min(a, b) + 10 - max(a, b));
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
        UnionFind uf(n);

        int minDistToZero = inf;
        
        for(int i = 0; i < n;i++) {
            int aux;
            cin>>aux;

            for(int j=0;j<4;j++) {
                key[i][j] = aux%10;
                aux /= 10;
            }

            for(int j=0;j<i;j++) {
                int d = 0;
                for(int k=0; k<4;k++) {
                    d += dist(key[j][k],key[i][k]);
                }
                edges.push_back((Edge){i,j,d});
            }

            int d = 0;
            for(int k=0; k<4;k++) {
                d += dist(0,key[i][k]);
            }
            minDistToZero = min(minDistToZero, d);
        }

        sort(edges.begin(), edges.end(), cmp);

        int cost = 0;
        for(Edge e : edges) {
            if(!uf.isSameSet(e.u, e.v)) {
                cost += e.weight;
                uf.unionSet(e.u, e.v);
            }
        }
        cout << cost+minDistToZero << endl;
    }

    return 0;
}