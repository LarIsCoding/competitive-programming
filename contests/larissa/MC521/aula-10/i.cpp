#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int find(int n, int k) {
    int lacunas = k / n;
    if(lacunas == 0) return k;
    int resto = k % n;
    return k - resto + find(n, lacunas + resto);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;cin>>n>>k;
        cout << find(n, k) << endl;
    }

    return 0;
}