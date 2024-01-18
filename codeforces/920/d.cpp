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
#define EPS 1e-9

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n,m;cin>>n>>m;
        int a[n], b[m];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];

        sort(a,a+n);
        sort(b,b+m);

        int la=0,ra=n-1;
        int lb=0,rb=m-1;

        ll r=0;
        while(la<=ra) {
            if(a[ra]-b[lb] > b[rb]-a[la]) {
                r+=(ll)(a[ra]-b[lb]);
                ra--;
                lb++;
            } else {
                r+=(ll)(b[rb]-a[la]);
                rb--;
                la++;
            }
        }
        cout<<r<<endl;
    }

    return 0;
}
// 1 2 4 6
// 1 2 3 3 5 7