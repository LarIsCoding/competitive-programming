#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int k, n;
        cin >> k >> n;

        int sequence[n];
        for(int j = 0; j < n; j++) {
            sequence[j] = 0;
        }

        long long int sum = 0;
        for(int j = 0; j < min(k, n); j++) {
            sum += j;
            sequence[j] = j;
            sum = sum % 1000007;
        }

        for(int j = k; j < n; j++) {
            sequence[j] = sum;
            sum += sequence[j] - sequence[j - k];
            sum = sum % 1000007;
        }

        while(sequence[n - 1] < 0) {
            sequence[n - 1] += 1000007;
        }

        cout << sequence[n - 1] % 1000007 << endl;
    }

    return 0;
}