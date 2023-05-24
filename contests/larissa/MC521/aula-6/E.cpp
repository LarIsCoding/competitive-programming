#include <bits/stdc++.h>

using namespace std;

long long numCartas[50000];

long long calcula(int x) {
    if(x == 1) {
        numCartas[1] = 2;
        return 2;
    }
    numCartas[x] = 2x + x - 1 + calcula(x - 1);
    return numCartas[x];
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    calcula(50000);

    while(t--) {
        int n;
        cin >> n;

        int acc = 0;
        while(n > 1) {
            acc++;
            long longmaior = upper_bound(numCartas + 1, numCartas + 50000, n);
            maior--;
            n -= *maior;
        }

        cout << acc << endl;
    }

    return 0;
}