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

class UnionFind {

    private:
    vi p, rank, setSize;
    int numSets;

    public:
    UnionFind(int N, vi &_p) {
        setSize = _p;
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
            setSize[x] += setSize[y];
        } else {
            p[x] = y;
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
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while(n != 0 || m != 0) {
        vi p(n);
        for(int i = 0; i <n;i++) {
            cin >> p[i];
        }
        int total = 0;
        UnionFind uf(n, p);
        for(int i =0;i<m;i++) {
            int op, a, b;cin>>op>>a>>b;
            a--;b--;
            if(op==1) {
                uf.unionSet(a, b);
            } else {
                if(uf.findSet(a) == uf.findSet(0)) {
                    if(uf.sizeOfSets(a) > uf.sizeOfSets(b)) total++;
                } else if(uf.findSet(b) == uf.findSet(0)) {
                    if(uf.sizeOfSets(b) > uf.sizeOfSets(a)) total++;
                }
            }
        }
        cout <<total<<endl;
        cin >> n >> m;
    }

    return 0;
}