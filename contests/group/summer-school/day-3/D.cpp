#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  long int n, operacao;
  cin >> n;
  while (n != 0)
  {
    operacao = ((n * (n + 1)) * ((2 * n) + 1)) / 6;
    cout << operacao << endl;
    cin >> n;
  }
  
  return 0;
}
