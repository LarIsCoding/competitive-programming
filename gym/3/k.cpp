#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

bool matrix[1005][1005];
pair<int, int> memo[1005][1005];

ll ans = 0;

void updatePosition(int i, int j) {
    ans -= (ll)max(memo[i][j].first + memo[i][j].second - 1, 0);

    if(matrix[i][j]) {
        memo[i][j] = mp(0, 0);
        return;
    }

    int goingLeft = memo[i - 1][j].second + 1;
    int goingDown = memo[i][j - 1].first + 1;
    memo[i][j] = mp(goingLeft, goingDown);

    ans += (ll)max(memo[i][j].first + memo[i][j].second - 1, 0);
}

void updateDiagonal(int x, int y, int n, int m) {
    for(int i = 1; x + i - 1 <= n && y + i - 1 <= m; i++) {
        if(x + i <= n) {
            updatePosition(x + i, y + i - 1);
        }
        if(y + i <= m) {
            updatePosition(x + i - 1, y + i);
        }
        if(x + i <= n && y + i <= m) {
            updatePosition(x + i, y + i);
        }
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            matrix[i][j] = false;
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            memo[i][j] = mp(0, 0);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            updatePosition(i, j);
        }
    }
    
    while(q--) {
        int x, y;
        cin >> x >> y;

        matrix[x][y] = !matrix[x][y];

        updatePosition(x, y);
        updateDiagonal(x, y, n, m);

        cout << ans << endl;
    }

    return 0;
}