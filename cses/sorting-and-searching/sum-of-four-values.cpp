#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int> > iii;
typedef vector<iii> viii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int a[1005];
viii c;

bool find(int x, int l, int r) {
    while(l < r) {
        int sum = c[l].first + c[r].first;
        if(sum < x) {
            l++;
        } else if(sum > x) {
            r--;
        } else {
            if(c[l].second.first != c[r].second.first && c[l].second.second != c[r].second.first && c[l].second.first != c[r].second.second && c[l].second.second != c[r].second.second) {
                cout << c[l].second.first << ' ' << c[l].second.second << ' ' <<  c[r].second.first << ' ' << c[r].second.second << endl;
                return true;
            }
            return find(x, l, r - 1) || find(x, l + 1, r); 
        }
    }
    return false;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    c.reserve((int)1e6 + 10);

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            c.push_back(mp(a[i] + a[j], mp(i + 1, j + 1)));
        }
    }

    sort(c.begin(), c.end());

    int l = 0, r = c.size() - 1;
    if(!find(x, l, r)) {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}