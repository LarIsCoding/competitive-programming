#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n;

    vector<int> adj[n];

    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    int folhas = 0;
    for(int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            folhas++;
        }
    }

    cout << folhas / 2 + folhas % 2 << endl;

    return 0;
}
