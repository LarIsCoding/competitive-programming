#include <iostream>

using namespace std;

typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int INF = 1e9;

int a[255];

int m;

int memo[255][510][255];

int dp(int index, int take, int smaller) {
    if(abs(take) > m) return INF;
    if(memo[index][take + 250][smaller] != -1) return memo[index][take + 250][smaller];

    if(index == 0 && take != 0) return memo[index][take + 250][smaller] = INF;
    if(index == 0) return memo[index][take + 250][smaller] = 0;

    int total = a[index] + take;

    int better = INF;

    for(int i = smaller; i * index <= m; i++) {
        int result = dp(index - 1, total - i, i);
        better = min(better, result + abs(total - i));
    }

    return memo[index][take + 250][smaller] = better;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < 255; i++) {
        for(int j = 0; j < 510; j++) {
            for(int k = 0; k < 255; k++) {
                memo[i][j][k] = -1;
            }
        }
    }

    cout << dp(n, 0, 0) << endl;

    return 0;
}