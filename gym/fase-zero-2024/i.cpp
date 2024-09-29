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
    int n,m;cin>>n>>m;
    string s;cin>>s;
    int t=n*m;
    vi v(t);

    int x=0;
    for(int i=0;i<m;i++) {
        if(s[i]=='1')x++;
    }
    v[0]=x;
    for(int i=1;i<t;i++) {
        if(s[i-1]=='1')x--;
        if(s[i+m-1]=='1')x++;
        v[i]=x;
    }

    bool fail=false;
    for(int i=0;i<m;i++) {
        vector<bool> w(m+1,false);
        for(int j=i;j<t;j+=m) {
            if(w[v[j]]) {
                fail=true;
                break;
            }
            w[v[j]]=true;
        }
        if(fail) break;
    }
    if(fail) cout<<"N\n";
    else cout<<"S\n";
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