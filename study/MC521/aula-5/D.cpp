#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x[4];
    cin >> x[0] >> x[1] >> x[2] >> x[3];

    int x1, x2, x3, x4;

    if(x[0] > x[3] && x[0] > x[1] && x[0] > x[2]) {
        int aux = x[3];
        x[3] = x[0];
        x[0] = aux;
    } else if(x[1] > x[3] && x[1] > x[3] && x[1] > x[2]) {
        int aux = x[3];
        x[3] = x[1];
        x[1] = aux;
    } else if(x[2] > x[3] && x[2] > x[1] && x[2] > x[3]) {
        int aux = x[3];
        x[3] = x[2];
        x[2] = aux;
    }

    int a = (x[0] + x[1] - x[2]) / 2;
    int c = x[1] - a;
    int b = x[2] - c;

    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}