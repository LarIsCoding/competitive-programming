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
        int n, k;cin>>n>>k;
        string s;cin>>s;
        vector<bool> inv(n+1,false);
        vector<ii> l(k);
        for(int i=0;i<k;i++) {
            cin>>l[i].f;
        }
        for(int i=0;i<k;i++) {
            cin>>l[i].s;
        }

        int q;cin>>q;
        while(q--) {
            int x;cin>>x;
            auto r=upper_bound(l.begin(),l.end(),mp(x,inf));
            r--;
            int diff=min(abs(r->f-x),abs(r->s-x));
            inv[r->f+diff]=!inv[r->f+diff];
        }

        string ans=s;
        for(int j=0;j<k;j++) {
            bool flip=false;
            for(int i=l[j].f;i<=(l[j].s+l[j].f)/2;i++) {
                if(inv[i]) flip=!flip;
                int diff=i-l[j].f;
                if(flip) swap(ans[i-1],ans[l[j].s-diff-1]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}