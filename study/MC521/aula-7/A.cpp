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

        char grid[2][n];

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        bool falhou = false;
        for(int i = 0; i < n; i++) {
            if(grid[0][i] == '1' && grid[1][i] == '1') {
                falhou = true;
                break;
            }
        }

        if(falhou) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}