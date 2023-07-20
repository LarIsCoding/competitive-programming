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

int a[(int)1e5+5];

class UnionFind {

    private:
    vi p, rank, setSize;
    int numSets;
    int maxSet;

    public:
    UnionFind(int N) {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++) 
            p[i] = i;
        maxSet = 1;
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
            maxSet = max(maxSet, setSize[x]);
        } else {
            p[x] = y;
            setSize[y] += setSize[x];
            maxSet = max(maxSet, setSize[y]);
        }

        if(rank[x] == rank[y]) rank[y]++;
    }

    int numDisjointSets() {
        return numSets;
    }

    int sizeOfSets(int i) {
        return setSize[findSet(i)];
    }

    int getMaxSet() {
        return maxSet;
    }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c,r;
    cin >> c >> r;

    while(c!=0 || r!=0) {
        map<string, int> m;

        for(int i = 0;i<c;i++) {
            string s;cin>>s;
            m[s]=i;
        }

        UnionFind uf(c);

        for(int i = 0;i<r;i++) {
            string s1, s2;cin>>s1>>s2;
            int id1=m[s1];
            int id2=m[s2];
            uf.unionSet(id1, id2);
        }
        cout << uf.getMaxSet() << endl;
        cin >> c >> r;
    }




    return 0;
}