#include <iostream>
#include <math.h>
using namespace std;
typedef long long int ll;

ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
  ll numero, elevado, mod = 1e9 + 7;
  cin >> numero;
  elevado = binpow(2, numero, mod);
  cout << elevado;
  return 0;

}
