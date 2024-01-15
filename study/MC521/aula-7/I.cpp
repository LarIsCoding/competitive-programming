#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int memo[21][201];
vi g[21];

int f(int i, int m) {
    if(memo[i][m] > -1) return memo[i][m];

    if(i == 0) return memo[i][m] = 0;
    if(m == 0) return memo[i][m] = -1;

    int best = -1;
    for(vi::iterator it = g[i].begin(); it != g[i].end(); it++) {
        if(*it <= m) {
            int result = f(i - 1, m - *it);
            if(result != -1) {
                best = max(best, result + *it);
            }
        }
    }

    return memo[i][m] = best;
}

void clearMemo() {
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 201; j++) {
            memo[i][j] = -1;
        }
    }
    for(int i = 1; i < 21; i++) {
        g[i].clear();
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        clearMemo();
        int m, c;
        cin >> m >> c;

        for(int i = 1; i <= c; i++) {
            int k, aux;
            cin >> k;

            for(int j = 0; j < k; j++) {
                cin >> aux;
                g[i].push_back(aux);
            }
        }

        int result = f(c, m);

        if(result == -1) cout << "no solution\n";
        else cout << result << endl;
    }

    return 0;
}