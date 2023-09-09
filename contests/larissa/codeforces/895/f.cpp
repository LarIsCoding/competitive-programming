#include <bits/stdc++.h>

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

vi adj[(int)1e5+5];
bool raiz[(int)1e5+5];

stack<int> r;

void dfs(int v) {
    r.push(v+1);
    for(auto it:adj[v]) {
        dfs(it);
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;cin>>n;

        vector<Edge> edges;
        for(int i=0;i<n;i++) {
            int b;cin>>b;
            edges.push_back({b-1,i,-1});
        }

        for(int i=0;i<n;i++) {
            cin>>edges[i].weight;
            edges[i].weight=-edges[i].weight;
        }

        UnionFind uf(n);

        sort(edges.begin(), edges.end(), cmp);
        memset(raiz,true,sizeof raiz);

        for(int i=0;i<n;i++) {
            adj[i].clear();
        }

        for(Edge e : edges) {
            if(!uf.isSameSet(e.u, e.v)) {
                adj[e.u].push_back(e.v);
                raiz[e.v]=false;
                uf.unionSet(e.u, e.v);
            }
        }

        for(int i=0;i<n;i++) {
            if(raiz[i]) {
                dfs(i);
            }
        }

        bool space=false;
        while(!r.empty()) {
            if(space)cout<<' ';
            space=true;
            cout<<r.top();
            r.pop();
        }
        cout<<endl;
    }

    return 0;
}