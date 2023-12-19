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

    memset(memo,inf,sizeof memo);
    memo[0]=0;
    for(int i=1;i<=n;i++) {
        int best=inf;
        int x=i;
        while(x>0) {
            int r=x%10;
            if(r!=0) best=min(best,memo[i-r]+1);
            x/=10;
        }
        memo[i]=best;
    }

    cout<<memo[n]<<endl;

    return 0;
}