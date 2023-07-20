#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n>> m;

    for(int i = 0; i < m; i++) {
        int a, b;cin>>a>>b;
    }

    for(int i = 0; i < n; i++) {
        cout << i%2;
    }
    cout << endl;

    return 0;
}