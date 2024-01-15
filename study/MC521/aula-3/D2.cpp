#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int m, n;
        cin >> m >> n;

        int a[m], pos[100001];

        for(int i = 0; i < m; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }

        int last = 0, tempo = 0, acc = 0;

        for(int i = 0; i < n; i++) {
            int aux;
            cin >> aux;

            if(pos[aux] < last) {
                tempo++;
            } else {
                acc += max(pos[aux] - last, 0);
                tempo += 1 + 2 * acc;
                last = pos[aux] + 1;
            }
        }

        cout << tempo << endl;
    }

    return 0;
}