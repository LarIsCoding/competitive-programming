#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    for(ll i = 0; i < t; i++) {
        ll n, l , r;
        cin >> n >> l >> r;
        vi num;
        num.assign(n, 0);

        for(ll j = 0; j < n; j++) {
            ll aux;
            cin >> aux;
            num[j] = aux;
        }

        sort(num.begin(), num.end());

        ll acc = 0;
        ll li = n - 1;
        ll ri = n - 1;
        for(ll j = 0; j < n - 1; j++) {
            if(ri < j) ri = j;
            if(li < j) li = j;
            while(num[j] + num[ri] > r && ri > j) ri--;
            while(num[j] + num[li] >= l && li > j) li--;
            acc += ri - li;
        }

        cout << acc << endl;
    }

    return 0;
}