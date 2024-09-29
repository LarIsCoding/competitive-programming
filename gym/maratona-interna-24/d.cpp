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
    int n,k;
    cin>>n>>k;

    int v[n];
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    double d=0;
    ll sum=0;
    for(int i=0;i<k;i++) {
        d+=(double)(v[i]*v[i]);
        sum +=v[i];
    }
    d-=(double)(sum*sum)/(double)k;

    int bestl=1;
    int bestr=k;
    double bestd=d;

    for(int i=k;i<n;i++) {
        d-=(double)(v[i-k]*v[i-k]);
        d+=(double)(sum*sum)/(double)k;
        sum-=v[i-k];
        sum+=v[i];
        d+=(double)(v[i]*v[i]);
        d-=(double)(sum*sum)/(double)k;

        if(d<bestd) {
            bestl=i-k+2;
            bestr=i+1;
            bestd=d;
        }
    }
    double ans = sqrt(bestd/(double)k);
    cout<<bestl<<' '<<bestr<<endl;
    cout<<setprecision(10)<<fixed<<ans<<endl;
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