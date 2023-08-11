#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        ll a, b, n, m;
        cin>>a>>b>>n>>m;

        ll pricePromotion = a*m;
        ll priceNotPromotion = b*(m+1);

        if(priceNotPromotion < pricePromotion) {
            cout << n * b << endl;
            continue;
        }

        ll total = pricePromotion * (n / (m + 1));
        total += min(a, b) * (n % (m + 1));
        cout << total << endl;
    }

    return 0;
}