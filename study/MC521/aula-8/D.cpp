#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int memo[(int)1e5 + 5][2];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    memo[0][0] = 1;
    memo[0][1] = 0;

    for(int i = 1; i <= n; i++) {
        if(s[i - 1] == 'm' || s[i - 1] == 'w') {
            memo[i][0] = 0;
            memo[i][1] = 0;
            continue;
        }

        memo[i][0] = (memo[i - 1][0] + memo[i - 1][1]) % mod;

        if((s[i - 1] == 'u' && s[i] == 'u') || (s[i - 1] == 'n' && s[i] == 'n')) {
            memo[i][1] = memo[i - 1][0];
        } else {
            memo[i][1] = 0;
        }
    }

    cout << memo[n][0] << endl;

    return 0;
}