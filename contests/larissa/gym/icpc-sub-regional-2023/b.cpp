#include <iostream>
#include <tgmath.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int v[(int)1e6+5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        int aux;cin>>aux;
        v[aux]=i;
    }

    int k=1;
    for(int i=2;i<=n;i++) {
        if(v[i]>v[i-1]) continue;
        k++;
    }

    cout<<ceil(log2((double)k))<<endl;

    return 0;
}