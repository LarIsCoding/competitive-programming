#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, c;
    cin >> a >> c;

    if(c % a != 0) {
        cout << -1 << endl;
    } else {
        cout << c << endl;
    }

    return 0;
}