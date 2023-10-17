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
        int n,k;cin>>n>>k;

        bool found=false;
        for(int i=0;i<n;i++) {
            int aux;cin>>aux;
            if(aux==k) found=true;
        }

        if(found) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}