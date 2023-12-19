#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vi letrasDiferentes, letrasIguais;
        letrasDiferentes.assign(26, 0);
        letrasIguais.assign(26, 0);

        int troca = 0;

        char palavra[n];

        for(int i = 0; i < n; i++) {
            cin >> palavra[i];
        }

        if(n % 2) {
            cout << -1 << endl;
            continue;
        }

        for(int i = 0; i < n / 2; i++) {
            if(palavra[i] != palavra[n - i - 1]) {
                letrasDiferentes[palavra[n - i - 1] - 'a']++;
            } else {
                letrasIguais[palavra[i] - 'a']++;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(letrasIguais[i] == 0) continue;

            for(int j = i + 1; j < 26; j++) {
                if(letrasIguais[j] == 0) continue;

                int menor = min(letrasIguais[i], letrasIguais[j]);

                troca += menor;
                letrasIguais[i] -= menor;
                letrasIguais[j] -= menor;

                if(letrasIguais[i] == 0) break;
            }
        }
    }

    return 0;
}