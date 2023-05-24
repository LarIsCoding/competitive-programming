#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        double b1, p1, b2, p2;
        cin >> b1 >> p1 >> b2 >> p2;

        if((b1 == 0 && b2 == 0) || (p1 == 0 && p2 == 0) || (b1 == 1 && b2 == 1)) {
            cout << "Lazy" << endl;
        }
        else if((b1 > b2 && p1 >= p2) || (b1 >= b2 && p1 > p2)) {
            cout << "HaHa" << endl;
        } else if ((b1 < b2 && p1 <= p2) || (b1 <= b2 && p1 < p2)) {
            cout << "Congrats" << endl;
        } else if(b1 == b2 && p1 == p2) {
            cout << "Lazy" << endl;
        } else {
            if (b1 < b2) {
                double p = pow(b2, p2/p1);
                if (b1 > p) {
                    cout << "HaHa" << endl;
                } else if(b1 < p) {
                    cout << "Congrats" << endl;
                } else {
                    cout << "Lazy" << endl;
                }
            } else {
                double p = pow(b1, p1/p2);
                if (p > b2) {
                    cout << "HaHa" << endl;
                } else if(p < b2) {
                    cout << "Congrats" << endl;
                } else {
                    cout << "Lazy" << endl;
                }
            }
        }
    }

    return 0;
}
