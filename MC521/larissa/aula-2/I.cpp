#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int w, n;
        cin >> w >> n;

        int acc = 0;
        int dist = 0;

        int lastX = 0;
        for(int i = 0; i < n; i++) {
            int x, wi;
            cin >> x >> wi;

            dist += x - lastX;
            lastX = x;

            int newAcc = acc + wi;

            if(newAcc > w) {
                dist += 2 * x;
                newAcc = wi;
            }
            if(newAcc == w) {
                dist += x;
                if(i < n - 1) dist += x;
                newAcc = 0;
            }
            acc = newAcc;
        }

        if(acc > 0) dist += lastX;

        cout << dist << endl;
    }

    return 0;
}