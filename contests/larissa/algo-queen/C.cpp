#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n], b[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int max = 0;
    int minPrice = 0;
    for(int i = 0; i < n; i++) {
        int mul = a[i] * b[i];

        if(mul == max) {
            minPrice = min(minPrice, a[i]);
        } else if(mul > max) {
            max = mul;
            minPrice = a[i];
        }
    }

    cout << minPrice << endl;

    return 0;
}