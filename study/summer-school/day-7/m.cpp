#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
#define inf (int)1e9
#define linf (ll)1e17
typedef pair<int,int> ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int n, vis[1005], v[1005];
vi cyc;

int dfs(int a){
    vis[a] = 1;
    if(vis[v[a]]) return 1;
    return 1 + dfs(v[a]);
}

int main(){_
    cin>>n;

    for(int i=1;i<=n;i++){
        int a; cin>>a; v[i]=a;
    }

    for(int i=1;i<=n;i++) if(!vis[i]) cyc.pb(dfs(i));
    
    ll ans = cyc[0];
    for(int i=1;i<sz(cyc);i++){
        ans=(cyc[i]*ans)/__gcd(ans,1LL*cyc[i]);
    }

    cout<<ans<<'\n';

    return 0;
}