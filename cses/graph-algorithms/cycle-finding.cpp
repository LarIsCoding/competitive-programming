#include <iostream>
#include <vector>
#include <algorithm>

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

vi solve() {
    vector<ll> d(n, linf);
    d[v] = 0;
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] < linf) {
                if (d[e.b] > d[e.a] + (ll)e.cost) {
                    d[e.b] = max(-linf, d[e.a] + (ll)e.cost);
                    p[e.b] = e.a;
                    x = e.b;
                    if(i==n-1) break;
                }
            }
        }
        if(x==-1) break;
    }
    vi path;
    if (x == -1) return path;

    int y = x;
    for (int i = 0; i < n; ++i)
        y = p[y];

    for (int cur = y;; cur = p[cur]) {
        path.push_back(cur);
        if (cur == y && path.size() > 1)
            break;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<m;i++) {
        int a,b,x;cin>>a>>b>>x;a--;b--;
        edges.push_back((Edge){a,b,x});
    }

    vi path;
    for(int i=0;i<n;i++) {
        v=i;
        path = solve();
        if(!path.empty()) break;
    }

    if(path.empty()) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    bool space=false;
    for(int it: path) {
        if(space) cout << ' ';
        else space=true;
        cout << it+1;
    }
    cout << endl;

    return 0;
}