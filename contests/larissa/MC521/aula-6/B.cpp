#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        if(k > n) {
            cout << "NO\n";
            continue;
        }

        if(n % 2 == 0 && k % 2 == 1) {
            if(2k > n) {
                cout << "NO\n";
                continue;
            }

            cout << "YES" << endl;
            for(int i = 0; i < k - 1; i++) {
                cout << "2 ";
            }
            cout << n - 2(k - 1) << endl;
            continue;
        }

        if(n % 2 == 1 && k % 2 == 0) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(int i = 0; i < k - 1; i++) {
            cout << "1 ";
        }
        cout << n - (k - 1) << endl;
        continue;
    }

    return 0;
}