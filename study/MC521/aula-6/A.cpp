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

        int maior = 0, posMaior, menor = 101, posMenor, aux;

        for(int i = 0; i < n; i++) {
            cin >> aux;
            if(aux > maior) {
                maior = aux;
                posMaior = i;
            }
            if(aux < menor) {
                menor = aux;
                posMenor = i;
            }
        }

        int possibilidade1 = max(posMaior, posMenor) + 1;
        int possibilidade2 = n - min(posMaior, posMenor);
        int possibilidade3 = min(posMaior, posMenor) + 1 + n - max(posMaior, posMenor);

        cout << min(min(possibilidade1, possibilidade2), possibilidade3) << endl;
    }

    return 0;
}