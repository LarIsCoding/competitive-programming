#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int cad[20];
int ch[20];

bool need[20];
bool found[20];

vii adj[(int)2e5+5];

int dfs_n(int p, int v, int n, int k) {
    if(v == n) return 0;
    for(auto it : adj[v]) {
        if(it.first == p) continue;
        int r = dfs_n(v, it.first, n, k);
        if(r >= 0) {
            for(int i = 0; i < k; i++) {
                if(cad[i] == v) need[i] = true;
                if(ch[i] == v) found[i] = true;
            }
            return r + it.second;
        }
    }
    return -1;
}

int dfs_chaves(int p, int v, int k) {
    int total = -1;
    for(int i = 0; i < k; i++) {
        if(need[i] && ch[i] == v && !found[i]) {
            total = 0;
            found[i] = true;
        }
    }
    for(auto it : adj[v]) {
        if(it.first == p) continue;
        int r = dfs_chaves(v, it.first, k);
        if(r >= 0) {
            return r + it.second;
        }
    }
    return total;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n>>k;

    for(int i = 0; i < k; i++) {
        cin >> cad[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> ch[i];
        need[i] = false;
        found[i] = false;
    }

    for(int i = 0; i<n-1;i++) {
        int a, b, w;cin>>a>>b>>w;
        adj[a].push_back(mp(b, w));
        adj[b].push_back(mp(a, w));
    }

    int total = dfs_n(0, 1, n, k);
    cout << total << endl;
    int chaves = dfs_chaves(0, 1, k);
    if(chaves > 0) total += 2*chaves;
    cout << total << endl;

    return 0;
}