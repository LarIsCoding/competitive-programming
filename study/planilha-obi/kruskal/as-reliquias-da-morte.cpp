#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef pair<double,double> ii;
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

ii pos[(int)1e3][2];

double distPointPoint(ii a, ii b) {
    return sqrt((a.first-b.first)*(a.first-b.first)-(a.second-b.second)*(a.second-b.second));
}

double distPointSeg(ii p, ii r1, ii r2) {
    double a1 = (r2.second-r1.second)/(r2.first-r1.first);
    double b1 = r1.second-a1*r1.first;

    double a2 = -1/a1;
    double b2 = -a2*p.first+p.second;

    cout << a1 << ' ' << b1 << endl;
    cout << a2 << ' ' << b2 << endl;

    double x = (b2-b1)/(a1-a2);
    double y = a1*x+b1;

    cout << x << ' ' << y << endl;

    cout << distPointPoint(p, mp(x,y)) << endl;
    
    if(x >= min(r1.first, r2.first) && x <= max(r1.first, r2.first)) {
        return distPointPoint(p, mp(x,y));
    }

    double d1 = distPointPoint(p, r1);
    double d2 = distPointPoint(p, r2);
    return min(d1,d2);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<Edge> edges;
    UnionFind uf(n);

    for(int i=0;i<n;i++) {
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        pos[i][0] = mp(x1,y1);
        pos[i][1] = mp(x2,y2);
        
        for(int j=0;j<i;j++) {
            edges.push_back((Edge){i, j, distPointSeg(pos[i][0], pos[j][0], pos[j][1])});
            cout << i << ' ' << j << ' ' << edges[edges.size()-1].weight << endl;
            edges.push_back((Edge){i, j, distPointSeg(pos[i][1], pos[j][0], pos[j][1])});
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    int cost = 0;

    for(Edge e : edges) {
        if(!uf.isSameSet(e.u, e.v)) {
            cost += e.weight;
            uf.unionSet(e.u, e.v);
        }
    }

    cout << cost << endl;

    return 0;
}