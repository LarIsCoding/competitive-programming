#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    int n0 = 0;
    char s[k];

    char aux;
    for(int i = 0; i < k; i++) {
        cin >> aux;
        s[i] = aux;
        if(aux == '0') n0++;
    }

    if(n0 != (k - n0)) {
        cout << 1 << endl;

        for(int i = 0; i < k; i++) {
            cout << s[i];
        }
        cout << endl;
    } else {
        cout << 2 << endl;;

        for(int i = 0; i < k - 1; i++) {
            cout << s[i];
        }
        cout << ' ' << s[k - 1] << endl;
    }

    return 0;
}