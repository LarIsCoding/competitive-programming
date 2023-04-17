#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    double r, xi, yi, x1, y1, x2, y2, sum;

    cin >> n >> r;

    cin >> xi >> yi;

    x1 = xi; y1 = yi;
    sum = 2 * r * atan(1)*4;

    for(int i = 0; i < n - 1; i++) {
        cin >> x2 >> y2;
        sum += sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        x1 = x2; y1 = y2;
    }

    sum += sqrt((x1 - xi)*(x1 - xi) + (y1 - yi)*(y1 - yi));

    cout << setprecision(2) << fixed << sum << endl;

    return 0;
}
