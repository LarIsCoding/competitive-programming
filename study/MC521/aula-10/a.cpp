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
        int n;
        cin >> n;

        int wrong[2];
        wrong[0] = 0; wrong[1] = 0;

        for(int i = 0; i < n; i++) {
            int aux; cin >> aux;

            if(aux%2 != i%2) {
                wrong[i%2]++;
            }
        }

        if(wrong[0] != wrong[1]) {
            cout << -1 << endl;
            continue;
        }

        cout << wrong[0] << endl;
    }

    return 0;
}