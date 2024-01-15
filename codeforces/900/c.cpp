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

ll pa[(int)2e5+5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    pa[0]=0;
    for(int i=1;i<=(int)2e5;i++) {
        pa[i]=pa[i-1]+i;
    }

    while(t--) {
        int n,k;
        ll x;cin>>n>>k>>x;
        ll minSum=pa[k];
        ll maxSum=pa[n]-pa[n-k];
        if(x<minSum || x>maxSum) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}