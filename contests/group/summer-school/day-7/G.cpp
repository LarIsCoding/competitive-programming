#include <iostream>

using namespace std;

long long pa(long long l) {
    return ((l) * (1 + l)) / 2;
}

long long paInversa(long long l, long long k) {
    long long linhas = l - k;
    return (linhas * (k - 1 + k - linhas)) / 2;
}

long long numElementos(long long l, long long k) {
    if(l > k) {
        return pa(k) + paInversa(l, k);
    }
    return pa(l);
}

long long find(long long x, long long k, long long l, long long r) {
    if(l == r) return l;
    long long m = (l + r) / 2;
    long long num = numElementos(m, k);
    if(x == num) return m;
    else if(x > num) {
        return find(x, k, m + 1, r);
    }
    return find(x, k, l, m);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t, k, x;
    cin >> t;
    
    for(long long i = 0; i < t; i++) {
        cin >> k >> x;
        cout << find(x, k, 1, 2*k - 1) << endl;
    }

    return 0;
}