#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int num[(int)1e4 + 5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,x;
    cin >> n>>x;

    memset(num, 0, sizeof(num));

    ll acc = 0;
    for(int i =0;i<n;i++) {
        int aux;cin>>aux;
        if(x%aux) continue;
        int y = x/aux;
        if(y>(int)1e4) continue;
        acc+=(ll)num[y];
        num[aux]++;
    }
    cout << acc << endl;

    return 0;
}