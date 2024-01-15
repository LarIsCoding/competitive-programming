#include <iostream>

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int adj[(int)1e5+5][2];
int out[(int)1e5+5];
pair<ii,ii> memo[(int)1e5+5];

pair<ii,ii> dp(int i) {
    if(i==0) {
        return mp(mp(1,1),mp(0,0));
    }
    if(memo[i].f.f!=-1) return memo[i];
    
    pair<ii,ii> l=dp(adj[i][0]);
    pair<ii,ii> r=dp(adj[i][1]);

    ll zeroRight=(l.f.s*r.f.s)%mod;
    ll oneRight=(l.f.f*(r.f.f+r.f.s+r.s.f+r.s.s)+r.f.f*(l.f.s+l.s.f+l.s.s)+l.s.f*r.s.s+l.s.s*r.s.f)%mod;
    ll zeroWrong=(l.s.s*(r.f.s+r.s.s)+r.s.s*(l.f.s))%mod;
    ll oneWrong=(l.s.f*r.f.s+l.s.f*r.s.f+r.s.f*l.f.s)%mod;

    if(out[i]==-1) {
        return memo[i]=mp(mp(zeroRight,oneRight),mp(zeroWrong,oneWrong));
    } else if(out[i]==0) {
        return memo[i]=mp(mp((zeroRight+oneWrong)%mod,0),mp((oneRight+zeroWrong)%mod,0));
    }
    return memo[i]=mp(mp(0,(oneRight+zeroWrong)%mod),mp(0,(zeroRight+oneWrong)%mod));
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        int a,b,s;cin>>a>>b>>s;
        adj[i][0]=a;
        adj[i][1]=b;
        out[i]=s;
    }

    for(int i=0;i<=n;i++) {
        memo[i].f.f=-1;
    }
    pair<ii,ii> r = dp(1);
    cout<<(r.s.f+r.s.s)%mod<<endl;

    return 0;
}