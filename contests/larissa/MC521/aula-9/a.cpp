#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int a[40], b[40];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(a, a+n);
        sort(b, b+n);

        for(int i = 0; i < k; i++) {
            if(a[i] < b[n - 1 - i]) {
                a[i] = b[n - 1 - i];
            } else {
                break;
            }
        }

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
        }
        cout << sum << endl;
    }

    return 0;
}