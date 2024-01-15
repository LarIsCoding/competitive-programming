#include <iostream>

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

        int s[n], f[n];
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            s[j] = x;
        }
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            f[j] = x;
        }

        int tempo = 0;
        bool espaco = false;
        for(int j = 0; j < n; j++) {
            if(espaco) cout << ' ';
            else espaco = true;

            if(s[j] >= tempo) {
                cout << f[j] - s[j];
            } else {
                cout << f[j] - tempo;
            }
            tempo = f[j];
        }
        cout << endl;
    }

    return 0;
}