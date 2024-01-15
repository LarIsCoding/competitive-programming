#include <iostream>
#include <map>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll linf = (ll)1e17;

int s[(int)1e5 + 10];
pair<int, int> memo[(int)1e5 + 10][25];
map<int, int> log;

pair<int, int> dp(int l, int r) {

    int i = log[r - l + 1];
    if(memo[l][i].first != -1) return memo[l][i];

    if(l == r) return make_pair(0, s[l]);

    int m = (l + r)/2;
    pair<int, int> r1 = dp(l, m);
    pair<int, int> r2 = dp(m + 1, r);

    int newSum = r1.first + r2.first + (r1.second + r2.second)/10;
    int mod = (r1.second + r2.second)%10;
    return memo[l][i] = make_pair(newSum, mod);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    int x = 2;
    for(int i = 1; i <= 25; i++) {
        log[x] = i;
        x *= 2;
    }
    for(int i = 0; i < 1e5 + 10; i++) {
        for(int j = 0; j < 25; j++) {
            memo[i][j] = make_pair(-1, -1);
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << dp(l, r).first << endl;
    }

    return 0;
}