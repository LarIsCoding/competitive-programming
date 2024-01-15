#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int m = n / 2;

        if(m % 2 == 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int acc = 0;
        for(int i = 1; i <= m; i++) {
            acc += i * 2;
            cout << i * 2 << ' ';
        }

        for(int i = 0; i < m - 1; i++) {
            acc -= i * 2 + 1;
            cout << i * 2 + 1 << ' ';
        }

        cout << acc << endl;
    }

    return 0;
}