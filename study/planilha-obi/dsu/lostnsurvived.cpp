
#include <iostream>
#include <vector>
#include <set>

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
    multiset<int> sizes;

    public:
    UnionFind(int N) {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++) {
            p[i] = i;
            sizes.insert(1);
        }
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
            sizes.erase(sizes.find(setSize[x]));
            sizes.erase(sizes.find(setSize[y]));
            setSize[x] += setSize[y];
            sizes.insert(setSize[x]);
        } else {
            p[x] = y;
            sizes.erase(sizes.find(setSize[y]));
            sizes.erase(sizes.find(setSize[x]));
            setSize[y] += setSize[x];
            sizes.insert(setSize[y]);
        }

        if(rank[x] == rank[y]) rank[y]++;
    }

    int numDisjointSets() {
        return numSets;
    }

    int sizeOfSets(int i) {
        return setSize[findSet(i)];
    }

    int diff() {
        if(numSets == 1) return 0;
        int ini = *sizes.begin();
        int end = *(--sizes.end());
        return end-ini;
    }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n>>q;

    UnionFind uf(n);

    while(q--) {
        int a,b;cin>>a>>b;
        uf.unionSet(a-1, b-1);
        cout << uf.diff() << endl;
    }

    return 0;
}