#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;
#define EPS 1e-9

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

int n, m, value;
bool impossible = false;
vector<vi> G;
vb visited;
vi degin, degout, a;

void dfs(int v, int p) {
    a[v] = value--;
    visited[v] = true;
    for (int u: G[v]) {
        if (u != p) {
            dfs(u, p);
        }
    }
}

void solve() {
    cin >> n >> m;

    G.assign(n+1, vi());
    degin.assign(n+1, 0);
    degout.assign(n+1, 0);
    a.assign(n+1, -1);
    visited.assign(n+1, false);

    value = n;

    for (int i = 0; i < n; i++) {
        int x, y;
        G[y].push_back(x);
        degin[x]++;
        degout[y]++;
    }

    int degout0 = -1, degin0 = -1;
    for (int i = 1; i <= n; i++) {
        if (degout[i] == 0) {
            if (degout0 == -1) {
                degout0 = i;
            } else {
                cout << "No\n";
                return;
            }
        }
    }

    if (degout0 == -1) {
        cout << "No\n";
        return;
    }

    dfs(degout0);

    if (impossible) {
        cout << "No\n";
        return;
    }

    for (int val: a) {
        cout << val << ' ';
    }
    cout << '\n';
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    //cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}