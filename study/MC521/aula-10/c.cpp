#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

string grid[105];
bool visited[105][105];

int dfs(int i, int j, int n) {
    if(i < 0 || i >= n || j < 0 || j >= n) return 0;
    if(grid[i][j] == '.') return 0;
    if(visited[i][j]) return 0;
    visited[i][j] = true;

    ii pos[4] = { mp(-1, 0), mp(1, 0), mp(0, -1), mp(0, 1) };

    int total = 0;
    for(int k = 0; k < 4; k++) {
        total = max(total, dfs(i + pos[k].first, j + pos[k].second, n));
    }

    if(total == 1 || grid[i][j] == 'x') return 1;
    return 0;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int k = 1; k <= t; k++) {
        int n;cin>>n;

        for(int i = 0; i < n; i++) {
            cin>>grid[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j  = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        int total = 0;
        for(int i = 0; i < n; i++) {
            for(int j  = 0; j < n; j++) {
                total += dfs(i, j, n);
            }
        }
        cout << "Case " << k << ": " << total << endl;
    }

    return 0;
}