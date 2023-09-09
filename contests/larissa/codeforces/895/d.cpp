#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

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
        ll n,x,y;cin>>n>>x>>y;

        ll divx=n/x;
        ll divy=n/y;

        ll mmc=(x*y)/__gcd(x,y);
        ll divxy=n/(mmc);

        ll m=divx-divxy;
        ll sum=(n+(n-m+1))*m/2;

        m=divy-divxy;
        ll sub=(1+m)*m/2;

        cout<<sum-sub<<endl;
    }

    return 0;
}