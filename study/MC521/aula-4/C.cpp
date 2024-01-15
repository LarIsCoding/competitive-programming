#include <iostream>
#include <queue>

using namespace std;

typedef queue<pair<int, int> > qii;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    while(cin >> k) {
        qii pairs;

        for(int y = k + 1; y <= k * 2; y++) {
            int cima = y - k;
            int baixo = y * k;

            if(baixo % cima) continue;

            int x = baixo / cima;

            pairs.push(make_pair(x, y));
        }

        cout << pairs.size() << endl;

        while(!pairs.empty()) {
            cout << "1/" << k << " = 1/" << pairs.front().first << " + 1/" << pairs.front().second << endl;
            pairs.pop();
        }
    }

    return 0;
}