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

    int t;
    cin >> t;

    while(t--) {
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;

        if(a1 == 0) {
            cout << 1 << endl;
            continue;
        }

        int sum = a1;

        int etapa1 = min(a2, a3);
        sum += 2 * etapa1;
        a2 -= etapa1;
        a3 -= etapa1;

        int etapa2 = min(a1 + 1, max(a2, a3));
        sum += etapa2;
        a1 -= etapa2;

        sum += min(a1 + 1, a4);

        cout << sum << endl;
    }

    return 0;
}