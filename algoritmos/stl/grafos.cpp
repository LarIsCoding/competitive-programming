#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V = 100;

    // Matriz de adjacencias
    // 1 se tem aresta, 0 se não tem
    // Wij se tem aresta, 0 se não tem
    // para grafos pequenos e densos (v <= 1000)
    int adjMat[V][V];

    // Vetor de adjacencias
    // Par (nó, peso)
    vector<vii> adjList;
    adjList.assign(V, vii());

    // Lista de arestas
    // Par (peso, (nó1, nó2))
    vector<pair<int, ii> > edgeList;

    return 0;
}