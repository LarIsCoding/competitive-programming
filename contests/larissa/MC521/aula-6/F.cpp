#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        int ones = 0, twos = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 1) {
                ones++;
            } else if (a == 2) {
                twos++;
            }
        }

        bool possible = false;
        if ((twos % 2 == 0 && ones % 2 == 0) || (twos % 2 != 0 && ones % 2 == 0 && ones > 0)) {
            possible = true;
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}