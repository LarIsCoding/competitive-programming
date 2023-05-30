#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

vi topics[200005], difficulties[200005];

int fat(int x) {
    cout << x << endl;
    if(x == 1 || x == 0) return 1;
    return x * fat(x - 1);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        topics[a].push_back(b);
        difficulties[b].push_back(a);
    }
    
    ll total = n * (n - 1) * (n - 2)/6;

    ll exclude = 0;
    for(int i = 1; i <= 200000; i++) {
        ll size = topics[i].size();
        if(size >= 2) {
            for(auto it = topics[i].begin(); it != topics[i].end(); it++) {
                exclude += (size - (ll)1) * ((ll)difficulties[*it].size() - (ll)1);
            }
        }
    }

    for(int i = 1; i <= 200000; i++) {
        ll size = difficulties[i].size();
        if(size >= 2) {
            for(auto it = difficulties[i].begin(); it != difficulties[i].end(); it++) {
                exclude += (size - (ll)1) * ((ll)topics[*it].size() - (ll)1);
            }
        }
    }

    cout << total - exclude/(ll)2 << endl;

    return 0;
}