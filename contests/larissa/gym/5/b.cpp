#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int a[(int)1e6+5];
map<int,int> quant;
ll mod = 1e9 + 7;

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
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return binpow(x, mod - 2, mod);
}

ll calcula(int n) {
    ll p=fat(n);
    ll q=1;
    for(auto it : quant) {
        q=(q*fat(it.second))%mod;
    }
    return (inv(p)*q)%mod;
}

ll update(ll v, ll from, ll to) {
    v = (v*inv(fat(from)))%mod;
    v = (v*fat(to))%mod;
    return v;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >>n>>k;

    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(quant.find(a[i]) == quant.end()) quant[a[i]] = 0;
        quant[a[i]]++;
    }

    memset(memo,0,sizeof memo);
    int res=calcula(n);
    cout << res <<endl;

    while(k--) {
        int id,b;cin>>id>>b;id--;

        res=update(res,quant[a[id]],quant[a[id]]-1);
        quant[a[id]]--;

        a[id]=b;
        if(quant.find(a[id]) == quant.end()) quant[a[id]] = 0;
        quant[a[id]]++;
        res=update(res,quant[a[id]]-1,quant[a[id]]);
        
        cout << res <<endl;
    }

    return 0;
}