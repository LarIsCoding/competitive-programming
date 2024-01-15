#include <iostream>

using namespace std;

typedef long long int ll;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        ll sum[2][n];

        ll aux;
        cin >> aux;

        sum[0][0] = aux;
        sum[1][0] = -aux;

        for(int i = 1; i < n - 1; i++) {
            cin >> aux;

            sum[0][i] = max(sum[0][i - 1] + aux, sum[1][i - 1] - aux);
            sum[1][i] = max(sum[0][i - 1] - aux, sum[1][i - 1] + aux);
        }

        cin >> aux;
        cout << max(sum[0][n - 2] + aux, sum[1][n - 2] - aux) << endl;
    }

    return 0;
}