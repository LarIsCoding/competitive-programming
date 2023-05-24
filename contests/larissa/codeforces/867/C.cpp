#include <iostream>

using namespace std;

typedef long long int ll;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        ll sum = 26;
        if(n == 4) {
            cout << sum << endl;
            continue;
        }

        sum += 5;
        if(n == 5) {
            sum += 6;
            cout << sum << endl;
            continue;
        }

        sum += (n - 5) * (6 + n);
        sum += n + 1;

        cout << sum << endl;
    }

    return 0;
}