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
        int n;cin>>n;
        int s1,e1;cin>>s1>>e1;
        bool failed=false;
        for(int i=1;i<n;i++) {
            int s,e;cin>>s>>e;
            if((s>=s1)&&(e>=e1)) {
                failed=true;
            }
        }
        if(failed) {
            cout<<-1<<'\n';
        } else {
            cout<<s1<<'\n';
        }
    }

    return 0;
}