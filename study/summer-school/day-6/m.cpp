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

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

void solve() {
    int n,m;cin>>n>>m;
    set<pair<ii,int> > s;
    for(int i=0;i<n;i++) {
        int l,r;cin>>l>>r;
        s.insert(mp(mp(l,r),i+1));
    }

    int last=0;
    vector<int> ans;
    set<ii> opt;

    while(!s.empty() && last<m) {
        while(!s.empty()&&s.begin()->first.first<=last+1) {
            opt.insert(mp(s.begin()->first.second,s.begin()->second));
            s.erase(s.begin());
        }
        if(opt.empty()) {
            cout<<"NO\n";
            return;
        }
        last=prev(opt.end())->first;
        ans.push_back(prev(opt.end())->second);
        opt.clear();
    }
    if(last<m) {
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    cout<<ans.size()<<endl;
    for(auto i:ans) {
        cout<<i<<' ';
    }
    cout<<endl;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    // cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}