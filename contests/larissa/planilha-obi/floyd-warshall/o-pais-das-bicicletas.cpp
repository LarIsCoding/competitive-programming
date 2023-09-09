#include <iostream>
#include <vector>

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

int d[105][105];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n>>m;
    int it=1;

    while(n!=0 || m != 0) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                d[i][j]=inf;
            }
        }

        for(int i=1;i<=n;i++) {
            d[i][i]=0;
        }

        for(int i=0;i<m;i++) {
            int a,b,h;cin>>a>>b>>h;
            d[a][b]=h;
            d[b][a]=h;
        }

        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (d[i][k] < inf && d[k][j] < inf)
                        d[i][j] = min(d[i][j], max(d[i][k],d[k][j]));
                }
            }
        }

        int k;cin>>k;

        cout << "Instancia " << it << endl;

        while(k--) {
            int i,j;cin>>i>>j;
            if(i==j) cout<<0<<endl;
            else cout << d[i][j] << endl;
        }
        cin >> n>>m;
        it++;
    }

    return 0;
}