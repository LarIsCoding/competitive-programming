#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s, t, slowest = 0;

    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        cin >> t;
        slowest = max(slowest, t);
    }

    int time = slowest * s;

    int miliseconds = 1000;
    
    if(time % miliseconds == 0) {
        time = time / miliseconds;
    } else {
        time = (time / miliseconds) + 1;
    }

    cout << time << endl;

    return 0;
}
