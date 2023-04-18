#include <bitset>

using namespace std;

void lacosAninhadosComPodas(int maxX, int maxY, int maxZ) {
    bool sol = false;
    int x, y, z;

    for(x = -maxX; x <= maxX && !sol; x++) {
        for(y = x + 1; y <= maxY && !sol; y++) {
            for(z = y + 1; z <= maxZ && !sol; z++) {
                // processa combinacao
            }
        }
    }
}

void permutacoes(int permutacao[], int n) {
    do {
        // processa permutacao
    } while(next_permutation(permutacao, permutacao + n));
}

void subconjuntos(int n) {
    // para cada subconjunto, O(2ˆn)
    for(int i = 0; i < (1 << n); i++) {

        // processa cada elemento do conjunto (O(n))
        for(int j = 0; j < n; j++) {

            // checa se j faz parte do conjunto
            if(i & (1 << j)) {
                // processa j
            }
        }
    }
}

// linhas, diagonais a esquerda e diagonais a direita
bitset<30> rw, ld, rd;
int n, ans = 0;

// Problema das n rainhas
void buscaRecursiva(int c) {
    if(c == n) {
        ans++;
        return;
    }

    // Try all possible rows
    for(int r = 0; r < n; r++) {

        if(!rw[r] && !ld[r - c + n - 1] && !rd[r + c]) {

            rw[r] = ld[r - c + n - 1] = rd[r + c] = true;   // flag
            buscaRecursiva(c + 1);
            rw[r] = ld[r - c + n - 1] = rd[r + c] = false; // restore
        }
    }
}

int main() {
    return 0;
}
