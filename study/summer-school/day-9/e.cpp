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

bool v[(int)1e4+5];

void solve() {
    int n,r;
    while(cin>>n>>r) {
        vector<bool> v(n+1,false);
        for(int i=0;i<r;i++) {
            int aux;cin>>aux;
            v[aux]=true;
        }
        bool notfound=false;
        for(int i=1;i<=n;i++) {
            if(!v[i]) {
                notfound=true;
                cout<<i<<' ';
            }
        }
        if(!notfound) cout<<'*';
        cout<<'\n';
    }
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