#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;

    long long aux;
    long long fila1[n], fila2[n];

    for(int i = 0; i < n; i++) {
        cin >> aux;
        fila1[i] = aux;
    }
    for(int i = 0; i < n; i++) {
        cin >> aux;
        fila2[i] = aux;
    }

    long long maxEsquerda = 0;
    long long maxDireita = 0;

    for(int i = 0; i < n; i++) {
        long long esquerda = max(maxDireita + fila1[i], maxEsquerda);
        long long direita = max(maxEsquerda + fila2[i], maxDireita);
        maxEsquerda = esquerda;
        maxDireita = direita;
    }

    cout << max(maxEsquerda, maxDireita) << endl;

    return 0;
}