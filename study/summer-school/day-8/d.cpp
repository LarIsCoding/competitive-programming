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
    int n,d;cin>>n>>d;
    int p[n][d];
    int v[1<<d][n];

    for(int i=0;i<n;i++) {
        for(int j=0;j<d;j++) {
            cin>>p[i][j];
        }
        for(int b=0;b<(1<<d);b++) {
            int x=0;
            for(int c=0;c<d;c++) {
                if(b&(1<<c)) x+=p[i][c];
                else x-=p[i][c];
            }
            v[b][i]=x;
        }
    }

    for(int i=0;i<(1<<d);i++) {
        sort(v[i],v[i]+n);
    }

    int best=0;
    for(int i=0;i<(1<<d);i++) {
        best=max(best,v[i][n-1]+v[i^((1<<d)-1)][n-1]);
    }

    cout<<best<<endl;
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