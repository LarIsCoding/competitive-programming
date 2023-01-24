#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m, c;
        cin >> m >> c;

        vector<int> hash[m];

        for (int j = 0; j < c; j++) {
            int aux;
            cin >> aux;

            int pos = aux % m;
            hash[pos].push_back(aux);
        }

        if (i != 0) {
            cout << '\n';
        }

        for (int j = 0; j < m; j++) {
            cout << j << " -> ";
            for (vector<int>::iterator it = hash[j].begin(); it != hash[j].end(); ++it) {
                cout << *it << " -> ";
            }
            cout << "\\" << endl;
        }
    }

    return 0;
}