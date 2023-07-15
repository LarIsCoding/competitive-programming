#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int x[(int)1e5+5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;cin>>n;

        for(int i = 0;i<n;i++) {
            cin>>x[i];
        }
        sort(x, x+n);

        ll sum = 0;
        int acc = 0;
        for(int i =0;i<n;i++) {
            if((ll)x[i] > sum) {
                sum+=(ll)x[i];
                acc++;
            }
        }
        cout << acc << ' ' <<sum<<'\n';
    }

    return 0;
}