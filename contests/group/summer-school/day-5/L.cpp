#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, t, d;
    cin >> n;

    long long stop = 0;
    for(long long i = 0; i < n; i++) {
        cin >> t >> d;
        stop = max(stop, t) + d;
    }

    cout << stop << endl;

    return 0;
}