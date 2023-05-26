#include <iostream>

using namespace std;

typedef long long int ll;

ll mod = (ll)1e9 + 7;

ll memo[(int)1e6 + 5];

ll fat(ll x) {
    if(memo[x]) return memo[x];
    if(x == 1 || x == 0) return 1;
    return memo[x] = (fat(x - 1) * x) % mod;
}

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

ll inv(ll x) {
    return binpow(x, mod - 2, mod);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    ll n = s.size();

    int numChar[26];
    for(int i = 0; i < 26; i++) {
        numChar[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        numChar[s[i] - 'a']++;
    }

    ll res = fat(n);
    for(int i = 0; i < 26; i++) {
        res = (res * inv(fat(numChar[i]))) % mod;
    }

    cout << res << endl;

    return 0;
}