#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++) {
        int n, k;
        cin >> n >> k;

        bool matrix[n][n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                bool aux;
                cin >> aux;
                matrix[i][j] = aux;
            }
        }

        int acc = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] != matrix[n - i - 1][n - j - 1]) {
                    matrix[i][j] = !matrix[i][j];
                    acc++;
                }
            }
        }

        int total = n * n;
        int sobra = total - acc;

        if(acc > k) {
            cout << "NO\n";
        } else if() 
        else if((k - acc) % 2 != 0) {

        } else {
            cout << "YES\n";
        }
    }

    return 0;
}