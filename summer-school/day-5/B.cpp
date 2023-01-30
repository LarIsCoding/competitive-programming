#include <iostream>
#include<map>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, c;
    cin >> n;

    map<int, int> maxNum;

    bool falhou = false;
    for(int i = 0; i < n; i++) {
        cin >> a >> c;
        if(maxNum.find(c) == maxNum.end()) {
            maxNum[c] = a;
        } else {
            if(a < maxNum[c]) {
                falhou = true;
                break;
            }
            maxNum[c] = a;
        }
    }

    if(falhou) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}
