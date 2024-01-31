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
    string sin;
    bool space=false;

    while(getline(cin,sin)) {
        if(space) cout<<endl;
        space=true;
        string s;
        for(char c:sin) {
            if(c!=' ')s+=c;
        }
        int n=s.size();
        // cout<<n<<endl;
        // cout<<s<<endl;

        vi best(n,0);

        for(int i=0;i<n-1;i++) {
            vi z=z_function(s.substr(i,n));
            vi cnt(n,1);
            for(int j:z) {
                for(int k=1;k<=j;k++) {
                    cnt[k]++;
                }
            }

            for(int j=0;j<n;j++) {
                best[j]=max(best[j],cnt[j]);
                // cout<<best[j]<<' ';
            }
            // cout<<endl;
        }

        for(int j=1;j<n;j++) {
            if(best[j]<=1) break;
            cout<<best[j]<<endl;
        }
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