#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        ll a, b;
        cin >> a >> b;
        cout << binpow(a, b, (ll)1e9 + 7) << endl;
    }

    return 0;
}
