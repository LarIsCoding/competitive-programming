#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;

    cin >> n;

    int q[n + 1];
    for(int i = 0; i < n + 1; i++) {
        q[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        for(int j = a; j <= b; j++) {
            q[j]++;
        }
    }

    int maxPeople = -1;
    for(int i = 0; i < n + 1; i++) {
        if(q[i] == i) maxPeople = i;
    }

    cout << maxPeople << endl;

    return 0;
}
