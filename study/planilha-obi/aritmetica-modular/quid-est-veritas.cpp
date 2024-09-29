#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;
#define EPS 1e-9

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

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

ll memo[1005];

ll fat(ll x) {
    if(memo[x]!=-1) return memo[x];
    if(x==0) return 1;
    return memo[x]=(x*fat(x-1))%mod;
}

void solve() {
    string s;
    memset(memo,-1,sizeof(memo));
    while(cin>>s) {
        vi v(26, 0);
        for(char c:s) {
            v[c-'A']++;
        }
        ll n=fat(s.size());
        for(int i:v) {
            n=(n*inv(fat(i)))%mod;
        }
        cout<<n<<endl;
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    //cin >> t;

    for(int i=0;i<t;i++) {
        solve();
    }

    return 0;
}