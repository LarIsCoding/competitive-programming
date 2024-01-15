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

        int a[n], b[n], ordenado[n];
        bool tem0 = false, tem1 = false;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            ordenado[i] = a[i];
        }

        sort(ordenado, ordenado + n);

        for(int i = 0; i < n; i++) {
            cin >> b[i];
            if(b[i] == 0) tem0 = true;
            else tem1 = true;
        }

        bool falhou = false;

        for(int i = 0; i < n; i++) {
            if(ordenado[i] != a[i]) {
                if(!tem0 || !tem1) {
                    falhou = true;
                    break;
                }
            }
        }

        if(falhou) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}