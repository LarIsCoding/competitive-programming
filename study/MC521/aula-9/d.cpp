#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int d[20005], k[20005];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while(n != 0 && m != 0) {
        for(int i = 0; i < n; i++) {
            cin >> d[i];
        }

        for(int i = 0; i < m; i++) {
            cin >> k[i];
        }

        sort(d, d+n);
        sort(k, k+m);

        int j = 0;
        int sum = 0;
        bool failed = false;

        for(int i = 0; i < n; i++) {
            while(j < m && k[j] < d[i]) j++;
            if(j == m) {
                failed = true;
                break;
            }
            sum += k[j];
            j++;
        }

        if(failed) {
            cout << "Loowater is doomed!\n";
        } else {
            cout << sum << endl;
        }

        cin >> n >> m;
    }

    return 0;
}