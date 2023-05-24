#include <bits/stdc++.h>

using namespace std;

#define BRANC0 1
#define PRETO 2

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    int cor[n + 1];
    for (int i = 0; i < n + 1; i++) {
        cor[i] = 1;
    }

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int, int> > num_arestas;
    for (int i = 1; i < n + 1; i++) {
        num_arestas.push_back(make_pair(adj[i].size(), i));
    }
    sort(num_arestas.begin(), num_arestas.end());

    int v = num_arestas[0].second;
    cor[v] = 0;
    for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++) {
        cor[*it] = 0;
    }

    for (int i = 1; i < n + 1; i++) {
        cout << cor[i];
        if (i != n) {
            cout << ' ';
        }
    }
    cout << endl;

    return 0;
}
