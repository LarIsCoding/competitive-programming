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
int moedas[100];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    for(int i=0;i<n;i++) {
        cin>>moedas[i];
    }

    memset(memo,0,sizeof memo);
    memo[0]=1;
    for(int i=1;i<=x;i++) {
        for(int j=0;j<n;j++) {
            int m=moedas[j];
            if(i-m>=0) {
                memo[i] = (memo[i]+memo[i-m])%mod;
            }
        }
    }

    cout << memo[x]<<endl;

    return 0;
}