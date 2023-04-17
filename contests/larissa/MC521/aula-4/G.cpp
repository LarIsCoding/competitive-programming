#include <iostream>
#include <math.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int k = 2; k < 30; k++) {

            int mul = pow(2, k) - 1;

            if(n % mul == 0) {
                cout << n / mul << endl;
                break;
            } 
        }
    }

    return 0;
}