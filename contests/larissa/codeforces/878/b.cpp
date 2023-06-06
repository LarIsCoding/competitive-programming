#include <iostream>
#include <math.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e10;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int maxPow = (k <= 30) ? (int)pow(2, k) : inf;
        int res = min(n + 1, maxPow);
        cout << res << endl;
    }

    return 0;
}