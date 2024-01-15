#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

vi adj[(int)3e5 + 5];
int parent[(int)3e5 + 5];

void process(int v) {
    for(auto it = adj[v].begin(); it != adj[v].end(); it++) {
        if(*it == parent[v]) continue;
        parent[*it] = v;
        cout << ' ' << *it;
        process(*it);
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int numNotLeaf = 0;
    int leaf;
    for(int i = 1; i <= n; i++) {
        if(adj[i].size() != 1) {
            numNotLeaf++;
        } else {
            leaf = i;
        }
    }

    if(numNotLeaf <= 1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    int neighbour = adj[leaf][0];
    parent[neighbour] = leaf;
    cout << neighbour << ' ' << leaf;

    process(neighbour);
    cout << "\n";

    return 0;
}
