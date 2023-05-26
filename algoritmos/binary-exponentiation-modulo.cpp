typedef long long int ll;

ll mod = 1e9 + 7;

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
