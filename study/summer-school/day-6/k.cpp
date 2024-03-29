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

vector<pair<int,bool> > events;

void solve() {
    int n,k;cin>>n>>k;

    for(int i=0;i<n;i++) {
        int l,r;cin>>l>>r;
        events.push_back(mp(l,false));
        events.push_back(mp(r,true));
    }

    sort(events.begin(),events.end());

    int acc=0;
    vector<ii> ans;
    int l=0;

    for(auto i:events) {
        if(i.second==false) {
            acc++;
            if(acc==k) l=i.first;
        } else {
            if(acc==k) ans.push_back(mp(l,i.first));
            acc--;
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans) {
        cout<<i.first<<' '<<i.second<<endl;
    }
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