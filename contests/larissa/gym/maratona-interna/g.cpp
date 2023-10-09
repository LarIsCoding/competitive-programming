#include <iostream>

using namespace std;

typedef pair<int,int> ii;
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

    ll n,m;
    cin>>n>>m;

    ll total=0;
    for(int i=0;i<n;i++) {
        total=(total+(max((ll)1,total)*m)%mod-i)%mod;
    }

    cout<<total<<endl;

    return 0;
}