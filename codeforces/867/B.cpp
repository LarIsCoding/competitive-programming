#include <iostream>

using namespace std;

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

        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int maior = max(a[0], a[1]);
        int menor = min(a[0], a[1]);

        int maiorPositivo = maior, segundoMaiorPositivo = menor, maiorNegativo = menor, segundoMaiorNegativo = maior;

        for(int i = 2; i < n; i++) {
            if(a[i] > 0) {
                if(a[i] > maiorPositivo) {
                    segundoMaiorPositivo = maiorPositivo;
                    maiorPositivo = a[i];
                } else if(a[i] > segundoMaiorPositivo) {
                    segundoMaiorPositivo = a[i];
                }
            } else {
                if(a[i] < maiorNegativo) {
                    segundoMaiorNegativo = maiorNegativo;
                    maiorNegativo = a[i];
                } else if(a[i] < segundoMaiorNegativo) {
                    segundoMaiorNegativo = a[i];
                }
            }
        }

        cout << max((ll)segundoMaiorPositivo * (ll)maiorPositivo, (ll)segundoMaiorNegativo * (ll)maiorNegativo) << endl;
    }

    return 0;
}