#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

vector<int> parent, rankk;

void make_set(int v) {
    parent[v] = v;
    rankk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rankk[a] < rankk[b])
            swap(a, b);
        parent[b] = a;
        if (rankk[a] == rankk[b])
            rankk[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

bool cmp(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n>>m;
    parent.resize(n);
    rankk.resize(n);

    vector<Edge> edges;
    vector<Edge> result;

    for(int i = 0;i<m;i++) {
        int x,y,z;cin>>x>>y>>z;
        Edge e = {x,y,z};
        edges.push_back(e);
    }

    for (int i = 0; i < n; i++)
        make_set(i);
    
    sort(edges.begin(), edges.end(), cmp);

    int cost = 0;

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    cout << cost << endl;

    return 0;
}