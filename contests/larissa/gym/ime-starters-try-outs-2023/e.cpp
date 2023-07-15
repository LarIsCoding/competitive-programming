#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

vi adj[(int)4e5+5];

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

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n>>m;

    map<int, int> a;

    for(int i =0;i<n;i++) {
        int aux;cin>>aux;
        a[aux]=i;
    }

    for(int i =0;i < m;i++) {
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    UnionFind uf(n);
    set<int> foi;
    foi.insert(a[1]);

    int max = 1;
    for(int i = 2; i<=n;i++) {
        if(a.find(i) == a.end()) break;
        for(auto it : adj[a[i]]) {
            if(foi.find(it)!=foi.end()) {
                uf.unionSet(a[i], it);
            }
        }
        if(uf.numDisjointSets() == n - i + 1) max = i;
        foi.insert(a[i]);
    }

    cout << max << endl;

    return 0;
}