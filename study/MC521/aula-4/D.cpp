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

        if(n <= 6) {
            cout << 15 << endl;
            continue;
        }

        int resto = n % 6;

        int sobra = 0;
        if(resto % 2) {
            sobra = 1;
        }

        ll tempo = (n + sobra) * 25 / 10;

        cout << tempo << endl;
    }

    return 0;
}