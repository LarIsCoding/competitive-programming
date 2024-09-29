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
    double e,v;cin>>e>>v;
    e*=1000;
    v/=3.6;
    ll t=(ll)(e/v);
    ll h=t/3600;
    h = (19+h)%24;
    ll m=(t%3600)/60;
    if(h<10)cout<<0;
    cout<<h<<':';
    if(m<10)cout<<0;
    cout<<m<<endl;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;

    for(int i=0;i<t;i++) {
        solve();
    }

    return 0;
}