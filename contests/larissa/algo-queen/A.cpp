#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, z, t;
    cin >> x >> y >> z >> t;

    int num = x / t;

    int q = min(num, y);

    cout << q * z << endl;

    return 0;
}