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
    int n;cin>>n;
    set<int> s;
    vi v(n);
    for(int i=0;i<n;i++) {
        s.insert(i+1);
        cin>>v[i];
    }
    vi ans(n);
    for(int i=n-1;i>=0;i--) {
        auto it=prev(s.end());
        for(int j=0;j<v[i];j++) it--;
        ans[i]=*it;
        s.erase(it);
    }
    bool space=false;
    for(int i:ans) {
        if(space)cout<<' ';
        space=true;
        cout<<i;
    }cout<<endl;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    //cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}