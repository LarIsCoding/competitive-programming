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

int memo[5005];

int fat(int n) {
    if(memo[n]!=-1)return memo[n];
    return memo[n]=n*fat(n-1);
}

int catalan(int n) {
    return fat(2*n)/(fat(n+1)*fat(n));
}

void solve() {
    int n;cin>>n;
    string s;cin>>s;
    int m=s.size();

    int l=0,r=0;
    int acc=0;
    for(int i=0;i<m;i++) {
        if(s[i])
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof memo);
    int t=1;
    //cin >> t;

    for(int i=0;i<t;i++) {
        solve();
    }

    return 0;
}