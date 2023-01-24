#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int diff = 2;
        int pot = 2;
        for (int i = 0; i < (n / 2 - 1); i++) {
            diff += 2 * pot;
            pot *= 2;
        }

        cout << diff << endl;
    }

    return 0;
}