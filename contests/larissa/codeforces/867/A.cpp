#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, t;
        cin >> n >> t;

        int a[n], b[n], maior = 0, index = -1;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for(int i = 0; i < n; i++) {
            if(a[i] + i > t) continue;
            if(b[i] > maior) {
                maior = b[i];
                index = i + 1;
            }
        }

        cout << index << endl;
    }

    return 0;
}