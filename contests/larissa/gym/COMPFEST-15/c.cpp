#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = 998244353;
const ll linf = (ll)1e17;
#define EPS 1e-9

vector<ii> adj[(int)1e5+5];
pair<int, ii> memo[(int)1e5+5];

pair<int, ii> dfs(int v) {
    if(memo[v].first!=-1) return memo[v];

    ll acc=0;
    ll num1=0;
    ll num0=0;

    for(ii it:adj[v]) {
        pair<int, ii> r = dfs(it.first);

        acc=(acc+(ll)r.first)%mod;

        if(it.second==1) {
            acc=(acc+(ll)r.second.first)%mod;
            r.second.second++;
        } else {
            r.second.first++;
        }

        acc=(acc+((ll)num1*(ll)r.second.first)%mod)%mod;
        num1=(num1+r.second.second)%mod;
        num0=(num0+r.second.first)%mod;
    }

    return memo[v]={acc,{num0,num1}};
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        int s;cin>>s;
        for(int j=0;j<s;j++) {
            int v,w;cin>>v>>w;
            adj[i].push_back({v,w});
        }
    }

    for(int i=1;i<=n;i++) {
        memo[i].first=-1;
    }

    pair<int, ii> r=dfs(1);
    cout<<r.first<<endl;

    return 0;
}