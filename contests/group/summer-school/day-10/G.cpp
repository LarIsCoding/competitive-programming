#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, x1, y1, x2, y2;

    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    int diffX, diffY;

    if(x >= x1 && x <= x2) {
        diffX = 0;
    } else {
        diffX = min(abs(x - x1), abs(x - x2));
    }

    if(y >= y1 && y <= y2) {
        diffY = 0;
    } else {
        diffY = min(abs(y - y1), abs(y - y2));
    }

    double maxL = sqrt((double)(diffX * diffX + diffY * diffY));

    cout << fixed << setprecision(3) << maxL << endl;

    return 0;
}
