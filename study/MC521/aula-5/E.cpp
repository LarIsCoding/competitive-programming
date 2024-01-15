#include <iostream>

using namespace std;

int p[262144];

int operacoes(int l, int r, int min, int max) {
    if(l + 1 == r) {
        if(p[l] == min) return 0;
        return -1;
    }

    for(int i = l; i < r; i++) {
        if(p[i] < min || p[i] > max) return -1;
    }
    int mid = (min + max) / 2;
    int m = (l + r) / 2;

    if(p[l] <= mid) {
        int opL = operacoes(l, m, min, mid);
        int opR = operacoes(m, r, mid + 1, max);

        if(opL == -1 || opR == -1) return -1;

        return opL + opR;
    }

    int opL = operacoes(l, m, mid + 1, max);
    int opR = operacoes(m, r, min, mid);

    if(opL == -1 || opR == -1) return -1;

    return opL + opR + 1;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int m;
        cin >> m;

        for(int i = 0; i < m; i++) {
            cin >> p[i];
        }

        cout << operacoes(0, m, 1, m) << endl;
    }

    return 0;
}