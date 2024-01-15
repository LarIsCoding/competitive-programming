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

int cartas[(int)2e5+5];
int memo[(int)2e5+5][3];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    memo[0][0]=0;
    memo[0][1]=0;
    memo[0][2]=0;
    for(int i=1;i<=n;i++) {
        cin>>cartas[i];
        memo[i][0]=max(memo[i-1][0],memo[i-1][1]);
        memo[i][1]=max(memo[i-1][0]-cartas[i],max(memo[i-1][1]-cartas[i],memo[i-1][2]-cartas[i]));
        memo[i][2]=memo[i-1][1]+2*cartas[i];
    }

    cout<<max(memo[n][0],max(memo[n][1],memo[n][2]))<<endl;

    return 0;
}