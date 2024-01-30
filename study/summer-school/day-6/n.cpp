#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 


void solve(){
    int n;cin>>n;

    ll acc=0;
    map<ll,int> vis;
    vis[0]=-1;
    int last=-1;
    int ans=0;

    for(int i=0;i<n;i++) {
        ll x;cin>>x;
        acc+=x;
        if(vis.find(acc)==vis.end()) {
            vis[acc]=i;
            continue;
        }
        if(vis[acc]+1>=last) {
            ans++;
            last=i;
            vis[acc]=i;
        } else {
            vis[acc]=i;
        }
    }

    cout<<ans<<endl;
}

int main() {
    
    int t=1;
    //cin>>t;
    for(int i = 0;i < t; i++){
        solve();
    }


    return 0;
}
