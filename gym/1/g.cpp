#include <iostream>

using namespace std;

typedef long long int ll;

double p[5005];
double memo[5005][10005];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    sort(p + 1, p + n + 1, greater<double>());

    int meio = 10005/2;

    for(int i = 0; i <= n; i++) {
        for(int j = -n; j <= n; j++) {
            if(j == 0 && i == 0) memo[i][meio + j] = (double)1;
            else if(i == 0) memo[i][meio + j] = (double)0;
            else if(j == -n) memo[i][meio + j] = memo[i - 1][meio + j + 1] * (1 - p[i]);
            else {
                memo[i][meio + j] = memo[i - 1][meio + j - 1]*p[i] + memo[i - 1][meio + j + 1]*(1 - p[i]);
            }
        }
    }

    double acc = 0;
    for(int j = 0; j <= n; j++) {
        double tmp = 0;
        for(int i = k; i <= n; i++) {
            tmp += memo[j][meio + i];
        }
        acc = max(acc, tmp);
    }

    cout << acc << endl;

    return 0;
}