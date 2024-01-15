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
    vi p, rank, setSize, eats, isEaten;
    int numSets;

    public:
    UnionFind(int N) {
        setSize.assign(N, 1);
        eats.assign(N, -1);
        isEaten.assign(N, -1);
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

    bool unionSet(int i, int j) {
        if(isSameSet(i, j)) return false;

        int x = findSet(i);
        int y = findSet(j);

        if(eats[x] != -1 && findSet(eats[x]) == y) return true;
        if(isEaten[x] != -1 && findSet(isEaten[x]) == y) return true;

        if(rank[x] > rank[y]) {
            p[y] = x;
            setSize[x] += setSize[y];
        } else {
            p[x] = y;
            setSize[y] += setSize[x];
        }

        if(rank[x] == rank[y]) rank[y]++;
        numSets--;

        if(eats[x] != -1 && eats[y] != -1) {
            unionSet(eats[x], eats[y]);
        } else if(eats[x] != -1) {
            eats[y] = eats[x];
        } else if(eats[y] != -1) {
            eats[x] = eats[y];
        }

        if(isEaten[x] != -1 && isEaten[y] != -1) {
            unionSet(isEaten[x], isEaten[y]);
        } else if(isEaten[x] != -1) {
            isEaten[y] = isEaten[x];
        } else if(isEaten[y] != -1) {
            isEaten[x] = isEaten[y];
        }

        return false;
    }

    bool eat(int x, int y) {
        x = findSet(x); y = findSet(y);

        if(eats[x] != -1 && findSet(eats[x]) == y) return false;

        if(x == y) return true;
        if(eats[y] != -1 && findSet(eats[y]) == x) return true;

        if(eats[x] != -1) {
            unionSet(eats[x], y);
        }
        if(isEaten[y] != -1) {
            unionSet(isEaten[y], x);
        }

        eats[x] = y;
        isEaten[y] = x;

        if(isEaten[x] != -1 && eats[y] != -1) {
            unionSet(isEaten[x], eats[y]);
        } else if(isEaten[x] != -1) {
            eats[y] = findSet(isEaten[x]);
            isEaten[findSet(isEaten[x])] = y;
        } else if(eats[y] != -1) {
            isEaten[x] = findSet(eats[y]);
            eats[findSet(eats[y])] = isEaten[x];
        }
        return false;
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

    int t;
    cin >> t;

    while(t--) {
        int n,k;cin>>n>>k;
        UnionFind uf(n);
        int acc = 0;

        while(k--) {
            int op, x,y;cin>>op>>x>>y;
            if(x < 1 || x > n || y < 1 || y > n) {
                acc++;continue;
            }
            x--;y--;
            if(op==1) {
                if(uf.unionSet(x, y)) acc++;
            } else {
                if(uf.eat(x, y)) acc++;
            }

            // cout << uf.findSet(0) << ' ' << uf.findSet(1) << ' ' << uf.findSet(2) << ' ' << uf.findSet(3) << ' ' << uf.findSet(4) << ' ' << uf.findSet(5) << endl;
        }

        cout << acc << endl;
    }

    return 0;
}