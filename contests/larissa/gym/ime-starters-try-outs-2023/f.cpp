#include <iostream>
#include <math.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

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
        int x,y,v,t;cin>>x>>y>>v>>t;
        double h = x*x+y*y;
        int d = v*t;
        d *= d;
        if(d >= h) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}