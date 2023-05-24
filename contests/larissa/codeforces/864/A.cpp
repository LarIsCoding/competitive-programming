#include <iostream>

using namespace std;

int isolar(int x, int y, int n, int m) {
    int distX = min(x - 1, n - x);
    int distY = min(y - 1, m - y);

    if(distX == 0 && distY == 0) return 2;
    if(distX == 0 || distY == 0) return 3;
    return 4;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        cout << min(isolar(x1, y1, n, m), isolar(x2, y2, n, m)) << endl;
    }

    return 0;
}