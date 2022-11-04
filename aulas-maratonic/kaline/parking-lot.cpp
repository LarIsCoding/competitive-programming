#include <iostream>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
  int n;
  cin >> n;
  long long vaga = 2 * n - 2;
  long long sobra_vaga = (vaga - n) + 1;
  long long opcoes_com_borda = binpow(3, sobra_vaga - 1);
  long long final = opcoes_com_borda * sobra_vaga * 4;
  long long opcao_sem_borda = opcoes_com_borda - 2;
  long long borda = binpow(4, sobra_vaga - 2) * binpow(3, 2) * (sobra_vaga - 2);
  long long sem_borda = binpow(4, sobra_vaga - 1) * 6;
  long long soma_opcoes = borda + sem_borda;
  cout << soma_opcoes << endl;
  return 0;

}
