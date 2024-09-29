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
    map<int, int> v1;
    map<int, int> v2;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int x;cin>>x;
            if(v1.find(x)==v1.end()) {
                v1[x]=0;
            }
            v1[x]++;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int x;cin>>x;
            if(v2.find(x)==v2.end()) {
                v2[x]=0;
            }
            v2[x]++;
        }
    }

    bool fail=false;
    for(pair<int, int> it:v1) {
        if(v2.find(it.first)==v2.end()) {
            fail=true;
            break;
        }
        if(it.second != v2[it.first]) {
            fail=true;
            break;
        }
    }

    if(fail) {
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
    }
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