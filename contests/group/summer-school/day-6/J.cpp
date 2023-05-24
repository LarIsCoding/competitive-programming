#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k, aux;
    cin >> n >> k;

    long long v[n];
    for(long long i = 0; i < n; i++) {
        cin >> aux;
        v[i] = aux;
    }
    sort(v, v + n);

    long long resta = k;
    long long sum = v[n/2];

    for(long long i = n / 2; i < n; i++) {
        if(i < n - 1) {
            long long q = i - n/2 + 1;
            long long diff = v[i + 1] - v[i];
            long long aumenta = diff * q;
            if(aumenta >= resta) {
                sum += resta / q;
                break;
            } else {
                resta -= aumenta;
                sum += diff;
            }
        } else {
            long long q = i - n/2 + 1;
            sum += resta / q;
            break;
        }
    }

    cout << sum << endl;

    return 0;
}