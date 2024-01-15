#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int a[(int)1e5+5];
vector<ll> prefix;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    prefix.assign(n, 0);
    cin>>a[0];
    prefix[0] = (ll)a[0];

    for(int i =1;i<n;i++) {
        cin>>a[i];
        prefix[i] = (ll)a[i] + prefix[i-1];
    }

    int m;cin>>m;
    for(int i =0;i<m;i++) {
        ll aux;cin>>aux;
        auto r = lower_bound(prefix.begin(), prefix.end(), aux);
        cout << *r << ' ' << r-prefix.begin() +1 << endl;
    }

    return 0;
}