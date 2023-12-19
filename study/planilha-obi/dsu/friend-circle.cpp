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
    vi p, rank, setSize;
    int numSets;

    public:
    UnionFind(int N) {
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

    int t;
    cin >> t;

    map<string, int> id;
    int index = 0;

    while(t--) {
        int n;cin>>n;
        UnionFind uf((int)2e5+5);
        for(int i=0;i<n;i++) {
            string s1,s2;cin>>s1>>s2;
            if(id.find(s1) == id.end()) {
                id[s1] = index;index++;
            }
            if(id.find(s2) == id.end()) {
                id[s2] = index;index++;
            }
            int id1 = id[s1], id2=id[s2];
            uf.unionSet(id1, id2);
            cout << uf.sizeOfSets(id1)<<endl;
        }
    }

    return 0;
}