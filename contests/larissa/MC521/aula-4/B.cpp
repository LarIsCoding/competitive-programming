#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, p, aux;
        cin >> n >> p;

        vi barras;
        barras.assign(p, 0);

        for(int i = 0; i < p; i++) {
            cin >> aux;
            barras[i] = aux;
        }

        bool achou = false;
        for(int i = 0; i < (1 << p); i++) {
            int acc = 0;
            for(int j = 0; j < p; j++) {
                if(i & (1 << j)) {
                    acc += barras[j];
                }
            }
            if(acc == n) {
                achou = true;
                break;
            }
        }

        if(achou) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}