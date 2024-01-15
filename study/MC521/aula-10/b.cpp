#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int num[1005];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int k = 1;
    for(int i = 0; k <= 1000; i++) {
        if(i%3 && i%10 != 3) {
            num[k] = i;
            k++;
        }
    }

    while(t--) {
        cin >> k;
        cout << num[k] << endl;
    }

    return 0;
}