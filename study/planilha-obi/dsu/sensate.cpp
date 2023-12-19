#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

class UnionFind {

    private:
    vi p, rank, setSize, poder;
    int numSets;

    public:
    UnionFind(int N, vi poderes) {
        poder = poderes;
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++) 
            p[i] = i;
    }

    int findSet(int i) {
        if(p[i] == i) return i;
        return p[i] = findSet(p[i]);
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if(isSameSet(i, j)) return;

        numSets--;
        int x = findSet(i);
        int y = findSet(j);

        if(rank[x] > rank[y]) {
            p[y] = x;
            poder[x] = max(poder[x], poder[y]);
            setSize[x] += setSize[y];
        } else {
            p[x] = y;
            poder[y] = max(poder[x], poder[y]);
            setSize[y] += setSize[x];
        }

        if(rank[x] == rank[y]) rank[y]++;
    }

    int numDisjointSets() {
        return numSets;
    }

    int sizeOfSets(int i) {
        return setSize[findSet(i)];
    }

    int powerOfSets(int i) {
        return poder[findSet(i)];
    }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m>>q;
    map<string, int> pessoas;
    vi poderes(n);
    for(int i =0;i<n;i++) {
        string nome; int poder;
        cin>>nome>>poder;
        pessoas[nome] = i;
        poderes[i] = poder;
    }
    UnionFind uf(n,poderes);
    for(int i =0;i<m;i++) {
        string a, b;cin>>a>>b;
        uf.unionSet(pessoas[a], pessoas[b]);    
    }
    for(int i =0;i<q;i++) {
        string a;cin>>a;
        int index = pessoas[a];
        if(uf.sizeOfSets(index) == 1) {
            cout << "S\n";
        } else if(uf.powerOfSets(index) <= 5) {
            cout << "S\n";
        } else if(poderes[index] >= 5) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}