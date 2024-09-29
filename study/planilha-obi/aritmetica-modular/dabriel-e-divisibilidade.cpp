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
    ll n;cin>>n;
    int nn=0;
    ll pot=1;
    while(n>0) {
        if(n%10) nn+=pot;
        pot*=2;
        n/=10;
    }

    int m;cin>>m;
    vector<int> v; 
    for(int i=0;i<m;i++) {
        int x;cin>>x;
        if(nn%x==0) {
            v.push_back(x);
        }
    }
    if(v.size()==0) {
        cout<<"Nenhum\n";
        return;
    }
    sort(v.begin(), v.end());
    bool space=false;
    for(int i=0;i<v.size();i++) {
        if(space) cout<<' ';
        cout<<v[i];
        space=true;
    }
    cout<<endl;
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