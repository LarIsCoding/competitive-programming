#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int memo[(int)1e6+5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    memset(memo,0,sizeof memo);
    memo[0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=6;j++) {
            if(i < j) continue;
            memo[i] = (memo[i-j]+memo[i])%mod;
        }
    }

    cout<<memo[n]<<endl;

    return 0;
}