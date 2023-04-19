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
        int a[n];

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n);

        int falhou = false;

        for(int i = 0; i < n - 1; i++) {
            if(a[i + 1] - a[i] > 1) {
                falhou = true;
                break;
            }
        }

        if(falhou) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}