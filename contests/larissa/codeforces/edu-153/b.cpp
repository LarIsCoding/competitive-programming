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

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int m,k,a1,ak;
        cin>>m>>k>>a1>>ak;

        int needk=m/k;
        int numk=min(needk,ak);
        int faltak=needk-numk;

        int need1=m-needk*k;

        int r=max(need1-a1,0);
        int sobra1=max(a1-need1,0);

        int cobre1=sobra1/k;
        r+=max(faltak-cobre1,0);

        cout<<r<<endl;
    }

    return 0;
}