#include <iostream>
#include <vector>
#include <map>

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
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

bool cmp(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}

int n, tin[200005], tout[200005], t, up[22][200005], mup[22][200005];
vector<ii> v[200005];
map<int,int> all[(int)2e5+5];

void dfs(int a,int p,int w){
    tin[a]=t++; up[0][a]=p; mup[0][a]=w;
    
    for(int i=1;i<=20;i++) up[i][a]=up[i-1][up[i-1][a]], mup[i][a]=max(mup[i-1][a],mup[i-1][up[i-1][a]]);

    for(auto b : v[a]) if(b.f!=p) dfs(b.f,a,b.s);

    tout[a]=t++;
}

bool anc(int a,int b){
    return (tin[a]<=tin[b] && tout[b]<=tout[a]);
}

int lca(int a,int b){
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int i=20;i>=0;i--)
        if(!anc(up[i][a],b)) a=up[i][a];

    return up[0][a];
}

int got(int a,int b){
    int resp=-inf;
    
    for(int i=20;i>=0;i--)
        if(!anc(up[i][a],b)){ resp=max(resp,mup[i][a]); a=up[i][a];}

    return max(resp,mup[0][a]);
}

int getBig(int a,int b){
    if(a==b) return 0;
    int c=lca(a,b);
    if(c==a) return got(b,a);
    if(c==b) return got(a,b);

    return max(got(a,c),got(b,c));
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin>>n>>m;

    vector<Edge> edges;

    for(int i=0;i<m;i++) {
        int a,b,c;cin>>a>>b>>c;a--;b--;
        edges.push_back((Edge){a,b,c});
        all[max(a,b)][min(a,b)]=c;
    }

    UnionFind uf(n);

    sort(edges.begin(), edges.end(), cmp);

    ll cost = 0;

    for(Edge e : edges) {
        if(!uf.isSameSet(e.u, e.v)) {
            cost += e.weight;
            uf.unionSet(e.u, e.v);
            v[e.u].push_back(mp(e.v,e.weight));
            v[e.v].push_back(mp(e.u,e.weight));
        }
    }

    dfs(0,0,0);

    int q;cin>>q;

    while(q--) {
        int u,v;cin>>u>>v;u--;v--;
        int x=getBig(u,v);
        cost+=all[max(u,v)][min(u,v)]-x;
        cout<<cost<<endl;
        cost-=all[max(u,v)][min(u,v)]-x;
    }

    return 0;
}