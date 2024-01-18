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
        int n,f,a,b;cin>>n>>f>>a>>b;
        int m[n+1];m[0]=0;
        int acc=0;
        bool failed=false;
        for(int i=1;i<=n;i++) {
            cin>>m[i];
        }
        for(int i=1;i<=n;i++) {
            ll lost=(ll)(m[i]-m[i-1])*(ll)a;
            if(lost > b || lost < 0) {
                f-=b;
            } else {
                f-=lost;
            }
            if(f<=0) {
                cout<<"NO\n";
                failed=true;
                break;
            }
        }
        if(!failed) cout<<"YES\n";
    }

    return 0;
}
