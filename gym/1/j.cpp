#include <iostream>

using namespace std;

int MAX = 30;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int x0, y0, xt, yt;
    cin >> x0 >> y0 >> xt >> yt;

    while(n--) {
        int x, y;
        cin >> x >> y;
    }

    for(int x = x0; x >= 0; x--) {
        cout << "left\n";
    }
    cout << "up\n";

    for(int x = x0; x >= 0; x--) {
        cout << "left\n";
    }
    cout << "down\n";

    for(int x = x0; x >= 0; x--) {
        cout << "right\n";
    }

    for(int y = y0; y <= MAX; y++) {
        cout << "up\n";
    }

    for(int x = 0; x <= MAX; x++) {
        cout << "right\n";
        for(int y = MAX + 1; y > yt; y--) {
            cout << "down\n";
        }
        for(int y = MAX + 1; y > yt; y--) {
            cout << "up\n";   
        }
    }

    cout << "right\n";

    for(int y = MAX + 1; y >= yt; y--) {
        cout << "down\n";
    }

    for(int y = -1; y >= -(MAX + 1); y--) {
        for(int x = MAX + 1; x > (xt + 1); x--) {
            cout << "left\n";
        }
        for(int x = MAX + 1; x > (xt + 1); x--) {
            cout << "right\n";
        }
        cout << "down\n";
    }

    for(int x = MAX + 1; x > xt; x--) {
        cout << "left\n";
    }

    for(int k = 0; k <= MAX + 1; k++) {
        for(int y = -(MAX + 2); y < yt; y++) {
            cout << "up\n";
        }

        for(int y = -(MAX + 2); y < yt; y++) {
            cout << "down\n";
        }

        for(int x = xt; x > xt - (MAX + 2 - k); x--) {
            cout << "left\n";
        }

        for(int y = -(MAX + 2); y < yt; y++) {
            cout << "up\n";
            cout << "right\n";
            cout << "left\n";
        }

        for(int y = -(MAX + 2); y < yt; y++) {
            cout << "down\n";
        }

        for(int x = xt; x > xt - ((MAX + 2) - k); x--) {
            cout << "right\n";
        }
    }

    return 0;
}
