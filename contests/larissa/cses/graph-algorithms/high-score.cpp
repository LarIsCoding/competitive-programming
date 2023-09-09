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

struct Edge {
    int a, b, cost;
};

int n, m, v;
vector<Edge> edges;
vi adj[2505];

vector<bool> visited;
bool canAccess(int i, int j) {
    if(i==j) return true;
    if(visited[i]) return false;
    visited[i]=true;

    for(int it : adj[i]) {
        if(canAccess(it,j)) return true;
    }
    return false;
}

ll solve() {
    vector<ll> d(n, linf);
    d[v] = 0;
    vector<int> p(n, -1);
    int x;

    vi negativeCycles;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges)
            if (d[e.a] < linf)
                if (d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = max(-linf, d[e.a] + e.cost);
                    p[e.b] = e.a;
                    x = e.b;
                    if(i==n-1) negativeCycles.push_back(e.b);
                }
    }

    for(int it : negativeCycles) {
        visited.assign(n,false);
        if (canAccess(it, n-1)) return -1;
    }
    return -d[n-1];
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    v=0;

    for(int i=0;i<m;i++) {
        int a,b,x;cin>>a>>b>>x;a--;b--;
        edges.push_back((Edge){a,b,-x});
        adj[a].push_back(b);
    }

    cout<<solve()<<endl;

    return 0;
}