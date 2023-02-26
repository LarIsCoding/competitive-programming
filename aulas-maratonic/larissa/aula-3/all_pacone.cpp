#include <bits/stdc++.h>

using namespace std;

int q[10000];

bool testa(int num, int n, int m) {
    if(num == 0) return true;

    int acc = 0;

    for(int i = 0; i < n; i++) {
        acc += q[i] / num;
    }

    return acc >= m;
}

int busca(int l, int r, int n, int m) {
    if(m == 0) return 0;

    if(l == r) {
        if(testa(l, n, m)) return l;
        return l - 1;
    }

    int meio = (l + r) / 2;

    if(testa(meio, n, m)) {
        return busca(meio + 1, r, n, m);
    }
    return busca(l, meio - 1, n, m);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        q[i] = aux;
    }

    cout << busca(0, 100000, n, m) << endl;

    return 0;
}