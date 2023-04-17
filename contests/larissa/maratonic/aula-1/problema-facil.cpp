#include <iostream>

using namespace std;

int main() {
    int n, m, k, v, aux;

    cin >> n >> m;
    int vetor[m];

    for (int i = 0; i < n; i++) {
        cin >> aux;
        vetor[i] = aux;
    }

    for (int i = 0; i < m; i++) {
        cin >> k >> v;
        
        int acc = 0;
        int pos = 0;
        for(int i = 0; i < n; i++) {
            if(vetor[i] == v) {
                acc++;
            }
            if(acc == k) {
                pos = i + 1;
                break;
            }
        }

        printf("%d\n", pos);
    }

    return 0;
}