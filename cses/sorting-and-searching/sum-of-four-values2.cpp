#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, pair<int, int> > iii;
typedef vector<iii> viii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int a[1005];
map<int, pair<int, int> > combinations;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int left = x - a[i] - a[j];
            if(combinations.find(left) != combinations.end()) {
                pair<int, int> found = combinations[left];
                cout << i + 1 << ' ' << j + 1 << ' ' << found.first << ' ' << found.second << endl;
                return 0;
            }
        }
        for(int j = 0; j < i; j++) {
            int sum = a[i] + a[j];
            combinations[sum] = mp(i + 1, j + 1);
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}