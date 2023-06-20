#include <iostream>
#include <iomanip>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

long double dp[2005];
long double memo[2005];

long double tx(int x, long double p, long double r) {
    if(memo[x] != -1) return memo[x];
    if(x == 0) return 0;
    return memo[x] = (tx(x - 1, p, r) + 1 + p * r) / (1 - p);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    long double t, r, p;

    cin >> c >> t >> r >> p;

    for(int i = 0; i < 2005; i++) {
        memo[i] = -1;
    }

    dp[0] = 0;
    for(int i = 1; i <= c; i++) {
        dp[i] = tx(i, p, r);
        for(int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + t + tx(i - j, p, r));
        }
    }

    cout << setprecision(20) << fixed << dp[c] + t << endl;

    return 0;
}