#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    vector<int> adj[n];
    pair<int, int> arestas[m];

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        arestas[i] = make_pair(a, b);
    }

    int q, aux;
    cin >> q;
    int operacoes[q];
    int operacoes_ordenado[q];

    for(int i = 0; i < q; i++) {
        cin >> aux;
        operacoes[i] = aux;
        operacoes_ordenado[i] = aux;
    }

    sort(operacoes_ordenado.begin(), operacoes_ordenado.end());

    int next = 0;
    for(int i = 0; i < m; i++) {
        if(i < operacoes_ordenado[next]) {
            adj[arestas[i].first] = arestas[i].second;
            adj[arestas[i].second] = arestas[i].first;
        } else {
            next++;
        }
    }

    return 0;
}