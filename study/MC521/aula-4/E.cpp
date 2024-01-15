#include <iostream>
#include <math.h>

using namespace std;

typedef long long int ll;

int findCubeRoot(ll n, ll l, ll r) {
    if(l > r) return -1;

    ll m = (r + l) / 2;
    ll m3 = pow(m, 3);

    if(m3 == n) {
        return m;
    }
    if(m3 > n) {
        return findCubeRoot(n, l, m - 1);
    }
    return findCubeRoot(n, m + 1, r);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        int a, b;

        for(a = 1; a < 10000; a++) {
            ll a3 = pow(a, 3);
            ll b3 = n - a3;

            b = findCubeRoot(b3, 1, 10000);
            if(b != -1) {
                break;
            }
        }

        if(b == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}