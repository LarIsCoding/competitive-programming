#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    string yourAnswer, friendAnswer;
    cin >> yourAnswer >> friendAnswer;

    int n = yourAnswer.length();

    int equal = 0;

    for(int i = 0; i < n; i++) {
        if(yourAnswer[i] == friendAnswer[i]) equal++;
    }

    int different = n - equal;

    int maxRight = min(equal, k) + min(different, n - k);

    cout << maxRight << endl;

    return 0;
}
