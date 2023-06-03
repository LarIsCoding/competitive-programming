#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e6;
const ll linf = (ll)1e17;

int memo[105][105];

int dp(int n, int k) {
    if(memo[n][k] != -1) return memo[n][k];
    if(k == 1) return memo[n][k] = 1;

    int num = 0;
    for(int i = 0; i <= n; i++) {
        num += dp(n - i, k - 1);
        num = num % mod;
    }
    return memo[n][k] = num;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < 105; i++) {
        for(int j = 0; j < 105; j++) {
            memo[i][j] = -1;
        }
    }

    while(n != 0) {
        cout << dp(n, k) << endl;
        cin >> n >> k;
    }

    return 0;
}