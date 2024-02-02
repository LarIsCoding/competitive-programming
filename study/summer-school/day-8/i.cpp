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

int q[(int)1e6+5];
int ans[(int)1e6+5];
bool vis[(int)1e6+5];
vi cycles[(int)1e6+5];

int findCycle(int i) {
    if(vis[i]) return 0;
    vis[i]=true;
    return 1+findCycle(q[i]);
}

void solve() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>q[i];
    }
    memset(vis,false, sizeof vis);
    for(int i=1;i<=n;i++) {
        int c=findCycle(i);
        if(c>0) cycles[c].push_back(i);
    }

    for(int i=1;i<=n;i++) {
        if(cycles[i].size()==0) continue;
        if(i%2==0 && cycles[i].size()%2) {
            cout<<-1<<endl;
            return;
        }
        if(i%2) {
            for(auto j:cycles[i]) {
                vi seq(i);
                int next=q[j];
                seq[0]=j;
                int id=2;
                while(next!=j) {
                    seq[id]=next;
                    next=q[next];
                    id=(id+2)%i;
                }
                for(int k=0;k<i;k++) {
                    ans[seq[k]]=seq[(k+1)%i];
                }
            }
        } else {
            for(int j=0;j<cycles[i].size(); j+=2) {
                int next1=cycles[i][j];
                int next2=cycles[i][j+1];

                do {
                    ans[next1]=next2;
                    next1=q[next1];
                    ans[next2]=next1;
                    next2=q[next2];
                } while(next1!=cycles[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<ans[i]<<' ';
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