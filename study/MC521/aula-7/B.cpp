#include <iostream>
#include <set>

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

        int lastSeen9[n], lastSeen22[n];
        set<int> front;

        for(int i = 0; i < n; i++) {
            cin >> lastSeen9[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> lastSeen22[i];
        }

        int index = n - 1, acc = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(front.find(lastSeen22[i]) != front.end()) {
                acc += index + 1;
                break;
            }
            while(lastSeen22[i] != lastSeen9[index]) {
                acc++;
                front.insert(lastSeen9[index]);
                index--;
            }
            index--;
        }

        cout << acc << endl;
    }

    return 0;
}