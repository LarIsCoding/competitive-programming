#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vb visitado;

void visita(vi adj[], int v) {
    for(vi::iterator it = adj[v].begin(); it != adj[v].end(); it++) {
        if(visitado[*it]) continue;
        visitado[*it] = true;
        visita(adj, *it);
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        vi adj[26];

        string input;
        cin >> input;

        while(input[0] != '*') {
            int a = input[1] - 'A';
            int b = input[3] - 'A';

            adj[a].push_back(b);
            adj[b].push_back(a);

            cin >> input;
        }

        visitado.assign(26, false);

        string vertices;
        cin >> vertices;

        int aux;
        int trees = 0;
        int acorns = 0;

        for(int i = 0; i < vertices.size(); i += 2) {
            int v = vertices[i] - 'A';
            if(visitado[v]) continue;

            visitado[v] = true;

            if(adj[v].size() == 0) {
                acorns++;
                continue;
            }

            trees++;
            visita(adj, v);
        }

        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
    }

    return 0;
}