#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

struct Artifact {
    int p;
    int w;
    int d;
};

bool cmp(Artifact a1, Artifact a2) {
    return a1.d<a2.d;
}

Artifact a[(int)1e4+5];
ll memo[(int)1e4+5][705][3];

ll dp(int i, int t, int used) {
    if(memo[i][t][used] != -1) return memo[i][t][used];
    if(i==0||t==0) return memo[i][t][used]=0;

    ll op1=dp(i-1,t,used);
    ll op2= (a[i].w <= t) ? dp(i-1,t-a[i].w,used) + (ll)a[i].p : 0;
    ll op3= (used < 2 && a[i].w <= t + a[i].d) ? dp(i-1,t-a[i].w+a[i].d,used+1)+(ll)a[i].p : 0;
    return memo[i][t][used]=max(op1,max(op2,op3));
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++) {
        int p,w,d;cin>>p>>w>>d;
        a[i]=(Artifact){p,w,d};
    }

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=705;j++) {
            for(int k=0;k<3;k++) {
                memo[i][j][k]=-1;
            }
        }
    }

    sort(a+1,a+n+1,cmp);

    cout << dp(n,m,0) << endl;

    return 0;
}