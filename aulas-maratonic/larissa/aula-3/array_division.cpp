#include <bits/stdc++.h>

using namespace std;

long long x[200000];

bool testa(long long soma, long long n, long long k) {
    long long acc = 0;
    long long kp = 1;

    long long i = 0;

    while(i < n && kp <= k) {
        if(acc + x[i] <= soma) {
            acc += x[i];
            i++;
        } else {
            kp++;
            acc = 0;
        }
    }

    return kp <= k;
}

long long busca(long long l, long long r, long long n, long long k) {
    if(l == r) return l;

    long long m = (l + r) / 2;

    if(testa(m, n, k)) {
        return busca(l, m, n, k);
    } else {
        return busca(m + 1, r, n, k);
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    long long aux;

    for(long long i = 0; i < n; i++) {
        cin >> aux;
        x[i] = aux;
    }

    cout << busca(1, 200000000000000, n, k) << endl;

    return 0;
}