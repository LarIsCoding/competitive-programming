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

        if(n == 1) {
            cout << 1 << endl;
            continue;
        }

        if(n % 2) {
            cout << -1 << endl;
            continue;
        }

        cout << n << ' ';
        for(int i = 1; i < n - 1; i += 2) {
            cout << n - i << ' ';
            cout << i + 1 << ' ';
        }
        cout << 1 << endl;
    }

    return 0;
}