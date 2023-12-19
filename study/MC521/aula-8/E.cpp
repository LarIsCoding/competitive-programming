#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, v;
    cin >> n >> v;

    int r = min(v, n - 1);

    for(int i = 2; i <= n - v; i++) {
        r += i;
    }

    cout << r << endl;

    return 0;
}