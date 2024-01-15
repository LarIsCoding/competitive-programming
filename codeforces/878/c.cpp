#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e10;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int a[(int)2e5 + 5];
ll memo[(int)2e5 + 5];

ll comb(ll n, ll k) {
    ll res = 0;
    for(ll i = 0; i < n - k + 1; i++) {
        res += n - i - k + 1;
    }
    return res;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < (int)2e5 + 5; i++) {
        memo[i] = -1;
    }

    while(t--) {
        int n, k, q;
        cin >> n >> k >> q;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        a[n] = inf;

        int acc = 0;
        ll sum = 0;
        for(int i = 0; i <= n; i++) {
            if(a[i] <= q) {
                acc++;
                continue;
            }

            sum += comb((ll)acc, (ll)k);
            acc = 0;
        }

        cout << sum << endl;
    }

    return 0;
}