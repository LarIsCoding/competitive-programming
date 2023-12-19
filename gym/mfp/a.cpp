#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int p[105];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;cin>>n;

        for(int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        for(int i = 1; i <= n; i++) {
            int j = i;
            bool space = false;
            do {
                if(space) cout << ' ';
                space = true;
                cout << j;
                j = p[j];
            } while(j != i);
            cout << endl;
        }
    }

    return 0;
}