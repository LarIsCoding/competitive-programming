#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;
#define EPS 1e-9

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve() {
    int m;cin>>m;

    for(int t=1;t<=m;t++) {
        string s;cin>>s;
        int n=s.size();
        vi best(n+1,0);

        for(int i=0;i<n-1;i++) {
            vi z=z_function(s.substr(i,n-i));
            for(int j=1;j<n-i;j++) {
                if(z[j]%j!=0) continue;
                for(int k=j;k<=z[j]+j;k+=j) {
                    best[k/j]=max(best[k/j],k);
                }
            }
        }
        best[1]=n;

        cout<<"Case #"<<t<<":";
        for(int j=1;j<=n;j++) {
            cout<<' '<<best[j];
        }
        cout<<endl;
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    //cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}