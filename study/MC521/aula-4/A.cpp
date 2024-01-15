#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> vb;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        char c, last = ' ';
        vb letters;
        letters.assign(26, false);

        bool falhou = false;
        for(int i = 0; i < n; i++) {
            cin >> c;

            if(c != last) {
                if(letters[c - 'A']) {
                    falhou = true;
                }
                last = c;
                letters[c - 'A'] = true;
            }
        }

        if(falhou) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}