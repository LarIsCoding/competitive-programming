#include <iostream>

using namespace std;

int a[100], b[100], memo[101][101];

int maiorPrefixo(int i, int j, int n, int m) {
    if(memo[i][j] >= 0) return memo[i][j];

    int op1 = 0, op2 = 0;

    if(i < n) op1 = a[i] + maiorPrefixo(i + 1, j, n, m);
    if(j < m) op2 = b[j] + maiorPrefixo(i, j + 1, n, m);

    return memo[i][j] = max(max(op1, op2), 0);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;

        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cin >> m;

        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                memo[i][j] = -1;
            }
        }

        cout << maiorPrefixo(0, 0, n, m) << endl;
    }

    return 0;
}