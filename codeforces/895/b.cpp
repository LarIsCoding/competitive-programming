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

ii trap[205];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;cin>>n;
        for(int i=0;i<n;i++) {
            int d,s;cin>>d>>s;
            trap[i]={d,s};
        }
        sort(trap,trap+n);

        int k=inf;
        for(int i=0;i<n;i++) {
            int step=(trap[i].s-1)/2;
            k=min(k,trap[i].f+step);
        }
        cout<<k<<endl;
    }

    return 0;
}