#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, aux;
        cin >> n;

        int c[3];
        c[0] = c[1] = c[2] = 0;

        for(int i = 0; i < n; i++) {
            cin >> aux;
            c[aux % 3]++;
        }

        int target = n / 3;

        int q = 0;

        int passa = max(0, c[0] - target);
        q += passa;
        c[0] -= passa;
        c[1] += passa;

        passa = max(0, c[1] - target);
        q += passa;
        c[1] -= passa;
        c[2] += passa;

        passa = max(0, c[2] - target);
        q += passa;
        c[2] -= passa;
        c[0] += passa;

        passa = max(0, c[0] - target);
        q += passa;
        c[0] -= passa;
        c[1] += passa;

        cout << q << endl;
    }

    return 0;
}