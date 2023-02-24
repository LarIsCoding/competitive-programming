#include <bits/stdc++.h>

using namespace std;

int MAX = 100000000;
int c[100000];

int producedUntilDay(int day, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += day / c[i];
    }
    return sum;
}

int busca(int l, int r, int n, int f) {
    if(r == l) return r;

    int m = (l + r) / 2;
    int producedM = producedUntilDay(m, n);

    if (producedM >= f) {
        return busca(l, m, n, f);
    }
    return busca(m + 1, r, n, f);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, f;
    cin >> n >> f;

    int aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        c[i] = aux;
    }

    cout << busca(1, MAX, n, f) << endl;

    return 0;
}