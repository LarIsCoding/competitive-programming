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
    ll x,y;
    cin>>x>>y;
    ll a=max(x,y);
    ll b=min(x,y);
    ll loops=0;

    while(a!=b) {
        ll diff=a-b;
        ll times=diff/b;
        loops+=times;
        a-=times*b;
        if(diff%b!=0) {
            loops++;
            x=b;
            b=a-b;
            a=x;
        }
    }
    cout<<loops<<endl;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i=0;i<t;i++) {
        solve();
    }

    return 0;
}