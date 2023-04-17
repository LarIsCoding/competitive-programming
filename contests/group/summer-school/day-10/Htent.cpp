#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> primos;

int find(int k, int l, int r) {
    if(l >= r) return l;

    int m = (r + l) / 2;

    if(primos[m] > k) {
        return find(k, l, m - 1);
    } else {
        return find(k, m + 1, r);
    }
}

int main(){
    long n;
    cin >> n;
    int passos = 0;
    bool ehPrimo[n + 1];

    for (int i = 0 ; i < n; i++) ehPrimo[i] = true;

    ehPrimo[0] = ehPrimo[1] = false;

    for (int i = 1; i < n; i++) {
        if(ehPrimo[i]) {
            primos.push_back(i);
            for(int j = i + i; j < n; j += i) {
                ehPrimo[j] = false;
            }
        }
    }

    int steps = 0;

    for(int i = 0; i < 2; i++) {
        int maiorPrimo;
        maiorPrimo = find(n, 0, primos.size() - 1);
        int q = 1, p = 1, diferenca = 0;
        cout << n << endl;

        while(!ehPrimo[p] || diferenca % 2 != 0) {
            q = primos[maiorPrimo];
            p = n - q;
            diferenca = q - p;
            cout << q << ' ' << p<< endl;
            maiorPrimo--;
        }

        n = q - p;
        steps++;
    }

    cout << steps << endl;

    return 0;
}
