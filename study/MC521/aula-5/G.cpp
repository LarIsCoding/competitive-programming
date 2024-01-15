#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int result = n;

        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                int div = n / i;
                if(div <= k) {
                    result = i;
                    break;
                } else if(i <= k) {
                    result = div;
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}