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
    int m;cin>>m;

    int v[m+1];
    v[0]=0;
    for(int i=1;i<=m;i++) {
        char c;
        cin>>c;
        v[i]=c-'0';
    }

    int vf[m+1];
    int res=0;
    for(int i=m;i>=0;i--) {
        int x=v[i]*2+res;
        vf[i]=x%10;
        res=x/10;
    }

    vf[m]++;

    if(vf[0]!=0) cout<<vf[0];
    for(int i=1;i<=m;i++) {
        cout<<vf[i];
    }
    cout<<'\n';
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