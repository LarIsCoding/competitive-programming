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
    int n;
    while(cin>>n) {
        vi prefixsum(n);
        int acc=0;
        for(int i=0;i<n;i++) {
            int x;cin>>x;
            acc+=x;
            prefixsum[i]=acc;
        }

        if(acc%3) {
            cout<<0<<'\n';
            continue;
        }

        int cnt=0;
        int interval=acc/3;

        for(int i=0;i<n;i++) {
            int val=prefixsum[i];
            if(binary_search(prefixsum.begin(),prefixsum.end(),val+interval)&&binary_search(prefixsum.begin(),prefixsum.end(),val+2*interval)) {
                cnt++;
            }
        }
        cout<<cnt<<'\n';
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