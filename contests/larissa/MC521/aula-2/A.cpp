#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int angulo;

    while(cin >> angulo) {
        if(angulo % 6 == 0) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}