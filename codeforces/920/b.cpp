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
        int n;cin>>n;
        string s,f;cin>>s>>f;

        int change0=0,change1=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='0'&&f[i]=='1') change1++;
            if(s[i]=='1'&&f[i]=='0') change0++;
        }
        cout<<max(change0,change1)<<endl;
    }

    return 0;
}