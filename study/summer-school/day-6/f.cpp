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

int a[(int)2e5], b[(int)2e5];

void solve() {
    int n;cin>>n;

    set<int> val;
    map<int,int> cnt;

    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(val.find(a[i])==val.end()) {
            val.insert(a[i]);
            cnt[a[i]]=0;
        }
        cnt[a[i]]++;
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
        if(val.find(b[i])==val.end()) {
            val.insert(b[i]);
            cnt[b[i]]=0;
        }
        cnt[b[i]]++;
    }

    vector<int> ans;
    for(int i=0;i<n;i++) {
        if(*prev(val.end())!=a[i]) {
            ans.push_back(*prev(val.end()));
            cnt[*prev(val.end())]--;
        } else {
            ans.push_back(*prev(prev(val.end())));
            cnt[*prev(prev(val.end()))]--;
        }
        cnt[a[i]]--;
    }

    cout<<"Yes\n";
    for(int i:ans) {
        cout<<i<<' ';
    }
    cout<<endl;
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