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
    int u, v;ll weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

bool cmp(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}

vi adj[(int)3e5+5];

vi passeio;

void dfs(int v, int p) {
    passeio.push_back(v);
    
    for(int u:adj[v]) {
        if(u!=p) {
            dfs(u,v);
            passeio.push_back(v);
        }
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<Edge> edges;
    UnionFind uf(n);

    for(int i=0;i<m;i++) {
        int a,b;ll c;cin>>a>>b>>c;a--;b--;
        edges.push_back((Edge){a,b,c});
    }

    sort(edges.begin(), edges.end(), cmp);

    ll cost = 0;
    vector<Edge> result;

    for(Edge e : edges) {
        if(!uf.isSameSet(e.u, e.v)) {
            cost += e.weight;
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
            uf.unionSet(e.u, e.v);
        }
    }

    cout<<(ll)2*cost<<endl;

    dfs(0,-1);

    cout<<passeio.size()<<endl;

    bool space=false;
    for(int v:passeio) {
        if(space)cout<<' ';
        space=true;
        cout<<v+1;
    }
    cout<<endl;

    return 0;
}