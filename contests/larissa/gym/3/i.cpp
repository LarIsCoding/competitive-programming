#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

vi adj[200005];
int p[200005];
bool color[200005];

bool found = false;

void paint(int v) {
    color[v] = true;
    for(auto it = adj[v].begin(); it != adj[v].end(); it++) {
        if(*it != p[v]) {
            paint(*it);
        }
    }
}

int dfs(int v, int n) {
    int total = 1;
    for(auto it = adj[v].begin(); it != adj[v].end(); it++) {
        if(*it != p[v]) {
            p[*it] = v;
            total += dfs(*it, n);
        }
    }
    if(total == n/2) {
        found = true;
        paint(v);
    }

    return total;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(color, false, sizeof(color));

    p[1] = 0;
    dfs(1, n);

    if(!found) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        cout << color[i] << ' ';
    }
    cout << endl;

    return 0;
}