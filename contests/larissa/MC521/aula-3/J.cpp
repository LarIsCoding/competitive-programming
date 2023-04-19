#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    while(cin >> n) {
        cin >> m;

        vi conexoes;
        conexoes.assign(26, 0);

        queue<ii> todo;
        vector<vi> adj;
        adj.assign(26, vi());

        for(int i = 0; i < 3; i++) {
            char v;
            cin >> v;
            v -= 'A';
            conexoes[v] = 3;
            todo.push(make_pair(v, 0));
        }

        for(int i = 0; i < m; i++) {
            char v1, v2;
            cin >> v1 >> v2;
            v1 -= 'A';
            v2 -= 'A';
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        int falta = n - 3;
        int years = 0;
        while(!todo.empty() && falta > 0) {
            int v = todo.front().first;
            int year = todo.front().second;
            for(vi::iterator it = adj[v].begin(); it != adj[v].end(); it++) {
                conexoes[*it]++;
                if(conexoes[*it] == 3) {
                    years = year + 1;
                    todo.push(make_pair(*it, years));
                    falta--;
                }
            } 
            todo.pop();
        }

        if(falta == 0) {
            cout << "WAKE UP IN, " << years << ", YEARS\n";
        } else {
            cout << "THIS BRAIN NEVER WAKES UP\n";
        }
    }

    return 0;
}