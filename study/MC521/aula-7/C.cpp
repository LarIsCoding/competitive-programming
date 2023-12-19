#include <iostream>

using namespace std;

int h[5000], w[5000];
int memo[5000][5000];

int findMaxSubsequence(int i, int last, int n, bool reverse) {
    int final = reverse ? n + 1 : 0;
    if(i == final) return 0;

    if(memo[i][last] > -1) return memo[i][last];

    int next = reverse ? 1 : -1;

    int op1 = findMaxSubsequence(i + next, last, n, reverse);

    int op2 = 0;
    if(last == n + 1 || h[i] < h[last]) {
        op2 = findMaxSubsequence(i + next, i, n, reverse) + w[i];
    }

    return memo[i][last] = max(op1, op2);
}

void clearMemo(int n) {
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= n + 1; j++) {
            memo[i][j] = -1;
        }
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 1; x <= t; x++) {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> h[i];
        }

        for(int i = 1; i <= n; i++) {
            cin >> w[i];
        }

        clearMemo(n);
        int increasing = findMaxSubsequence(n, n + 1, n, false);
        clearMemo(n);
        int decreasing = findMaxSubsequence(1, n + 1, n, true);

        if(increasing >= decreasing) {
            cout << "Case " << x << ". Increasing (" << increasing << "). Decreasing (" << decreasing << ").\n";
        } else {
            cout << "Case " << x << ". Decreasing (" << decreasing << "). Increasing (" << increasing << ").\n";
        }
    }

    return 0;
}