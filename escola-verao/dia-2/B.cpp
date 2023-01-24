#include <bits/stdc++.h>

using namespace std;

#define INF 1000001

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int l, n;
        cin >> l >> n;

        int menor = 0;
        int maior = 0;

        for (int j = 0; j < n; j++) {
            int pos;
            cin >> pos;

            menor = max(menor, min(pos, l - pos));
            maior = max(maior, max(pos, l - pos));
        }

        cout << menor << ' ' << maior << endl;
    }

    return 0;
}