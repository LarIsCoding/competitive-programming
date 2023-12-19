#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

vi adj[(int)1e5];

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


vi p;
int maxDist = 0;

int dfs(int v) {
    vi dist;
    for(auto it : adj[v]) {
        if(p[v] == it) continue;
        p[it] = v;
        int l = dfs(it);
        dist.push_back(l+1);
    }
    if(dist.size() == 0) return 0;
    if(dist.size() == 1) {
        maxDist = max(maxDist, dist[0]);
        return dist[0];
    }
    sort(dist.begin(), dist.end());
    int end = dist.size() - 1;
    maxDist = max(maxDist, dist[end] + dist[end-1]);
    return dist[end];
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n>>m;

    priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;

    for(int i = 0;i<m;i++) {
        int u,v,c;cin>>u>>v>>c;
        u--;v--;
        pq.push(mp(c, mp(u, v)));
    }

    UnionFind uf(n);

    ll acc = 0;
    while(uf.numDisjointSets() > 1) {
        auto it = pq.top(); pq.pop();
        int u = it.second.first, v =it.second.second;
        if(uf.isSameSet(u,v)) continue;
        uf.unionSet(u,v);
        acc += (ll)it.first;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    p.assign((int)1e5, -1);
    dfs(0);

    cout << acc << endl << maxDist << endl;

    return 0;
}