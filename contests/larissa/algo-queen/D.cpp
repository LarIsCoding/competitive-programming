#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;

        while(q--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            int distx = abs(x1 - x2);
            int disty = abs(y1 - y2);

            if(distx % k != 0 || disty % k != 0) {
                cout << -1 << endl;
                continue;
            }

            int result = distx / k + disty / k;
            cout << result << endl;
        }
    }

    return 0;
}