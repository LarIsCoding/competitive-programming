#include <iostream>
#include <map>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int m, p;
        map<string, double> produtos;

        cin >> m;

        for(int j = 0; j < m; j++) {
            string produto;
            double preco;

            cin >> produto >> preco;

            produtos[produto] = preco;
        }

        double sum = 0;

        cin >> p;
        for(int j = 0; j < p; j++) {
            string produto;
            double quantidade;

            cin >> produto >> quantidade;

            sum += produtos[produto] * quantidade;
        }

        printf("R$ %.2f\n", sum);
    }

    return 0;
}