#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

ii a[5005];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        a[i] = mp(aux, i + 1);
    }

    sort(a, a+n);

    for(int i = 0; i < n; i++) {
        int value = a[i].first;
        int index = a[i].second;

        int left = x - value;

        int l = 0, r = n - 1;

        while(l < r) {
            if(l == i) {
                l++;
                continue;
            }
            if(r == i) {
                r--;
                continue;
            }

            int sum = value + a[l].first + a[r].first;
            if(sum == x) {
                cout << index << ' ' << a[l].second << ' ' << a[r].second << endl;
                return 0;
            } else if(sum < x) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}