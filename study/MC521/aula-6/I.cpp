#include <iostream>

using namespace std;

int w[1001], p[1001], memo[31][1001];

int calcula(int W, int i) {
    if(memo[W][i] > -1) return memo[W][i];
    if(W == 0 || i == 0) return memo[W][i] = 0;

    int op1 = 0;
    if(W >= w[i]) op1 = calcula(W - w[i], i - 1) + w[i];
    int op2 = calcula(W, i - 1);

    return memo[W][i] = max(op1, op2);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= 30; j++) {
                memo[i][j] = -1;
            }
        }

        for(int i = 1; i <= n; i++) {
            cin >> p[i] >> w[i];
        }

        int g;
        cin >> g;

        int acc = 0;
        for(int i = 0; i < g; i++) {
            int aux;
            cin >> aux;
            acc += calcula(aux, n);
        }
        cout << acc << endl;
    }

    return 0;
}