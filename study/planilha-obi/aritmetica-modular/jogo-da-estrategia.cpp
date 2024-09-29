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
    int j, r;cin>>j>>r;
    int v[j];
    memset(v, 0, sizeof(v));
    
    for(int i=0;i<j*r;i++) {
        int x;cin>>x;
        v[i%j]+=x;
    }

    int m=-1;
    int res=-1;
    for(int i=0;i<j;i++) {
        if(v[i]>=m) {
            m=v[i];
            res = i+1;
        }
    }

    cout<<res<<endl;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    for(int i=0;i<t;i++) {
        solve();
    }

    return 0;
}