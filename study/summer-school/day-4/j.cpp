#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

int n, m;
int dp[101][101][1201];
ii p[101][101];

int exp(int v, int b) {
    int ans = 0;
    while (v % b == 0) {
        ans++;
        v /= b;
    }
    return ans;
}

void solve() {
    cin >> n >> m;

    memset(dp, -1, sizeof(int)*101*101*1201);
    memset(p, 0, sizeof(int)*101*101);

    for (int i = 1; i <= n; i++){ 
        for (int j = 1; j <= m; j++) {
            int v;
            cin >> v;
            p[i][j] = {exp(v, 2), exp(v, 3)};
        }
    }

    for (int i = 1; i <= n; i++)
        dp[i][0][0] = 0;

    for (int j = 1; j <= m; j++)
        dp[0][j][0] = 0;

    for (int i = 1; i <= n; i++){ 
        for (int j = 1; j <= m; j++) {
            auto [p2, p3] = p[i][j];
            for (int y = p3; y <= 1200; y++) {
                int x = max(dp[i-1][j][y-p3], dp[i][j-1][y-p3]);
                if (x != -1)
                    dp[i][j][y] = x + p2;
            }
        }
    }

    // for (int i = 1; i <= n; i++) { 
    //     for (int j = 1; j <= m; j++) {
    //         cout << "| ";
    //         for (int y = 0; y <= n+m-1; y++) {
    //             cout << dp[i][j][y] << ' ';
    //         }
    //         cout << "|";
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for (int i = 0; i <= 1200; i++) {
        ans = max(ans, min(i, dp[n][m][i]));
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin>>t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}
