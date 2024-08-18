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

ll area(vector<ii> &v) {
    ll a=0;
    int n=v.size();
    for(int i=0;i<n;i++) {
        a+=(ll)v[i].f*(ll)v[(i+1)%n].s;
        a-=(ll)v[i].s*(ll)v[(i+1)%n].f;
    }
    return abs(a/2);
}

// A = I + B/2 - 1
// Onde A é área, I é o número de pontos internos e B é o número de pontos na borda
ll picks_formula(ll a, ll b) {
    return a - b/2 + 1;
}

void solve() {
    int n;cin>>n;

    vector<ii> v(n);
    for(int i=0;i<n;i++) {
        int x,y;cin>>x>>y;
        v[i]={x,y};
    }
    ll a=area(v);

    ll b=0;
    for(int i=0;i<n;i++) {
        ll dx=abs(v[i].f-v[(i+1)%n].f);
        ll dy=abs(v[i].s-v[(i+1)%n].s);
        ll m=__gcd(dx,dy);
        b+=m;
    }

    ll i=picks_formula(a,b);

    cout<<i<<' '<<b<<endl;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    //cin >> t;

    for(int i=0;i<t;i++) {
        solve();
    }

    return 0;
}