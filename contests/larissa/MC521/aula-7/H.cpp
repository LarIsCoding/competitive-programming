#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string environment;
        cin >> environment;

        int max = 1, min = 1;
        for(int i = 0; i < n - 1; i++) {
            max++;
            if(environment[i] == '0') {
                max--;
                min = 1;
            } else {
                min++;
                max = i + 2;
            }
            if(i != 0) cout << ' ';
            cout << max - min + 1;
        }
        cout << endl;
    }

    return 0;
}