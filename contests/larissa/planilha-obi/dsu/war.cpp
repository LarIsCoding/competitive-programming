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
    vi p, rank, setSize, enemy;
    int numSets;

    public:
    UnionFind(int N) {
        enemy.assign(N, -1);
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

    bool areFriends(int i, int j) {
        return findSet(i) == findSet(j);
    }

    bool areEnemies(int i, int j) {
        if(enemy[findSet(i)] == -1) return false;
        if(findSet(enemy[findSet(i)]) == findSet(j)) return true;
        return false;
    }

    bool setFriends(int i, int j) {
        if(areFriends(i, j)) return true;
        if(areEnemies(i, j)) return false;

        numSets--;
        int x = findSet(i);
        int y = findSet(j);

        if(rank[x] > rank[y]) {
            p[y] = x;
            setSize[x] += setSize[y];
            if(enemy[x] == -1) {
                enemy[x] = enemy[y];
            }
        } else {
            p[x] = y;
            setSize[y] += setSize[x];
            if(enemy[y] == -1) {
                enemy[y] = enemy[x];
            }
        }
        if(enemy[x] != -1 && enemy[y] != -1) {
            setFriends(enemy[x], enemy[y]);
        }

        if(rank[x] == rank[y]) rank[y]++;
        return true;
    }

    bool setEnemies(int i, int j) {
        if(areEnemies(i, j)) return true;
        if(areFriends(i, j)) return false;

        int x = findSet(i);
        int y = findSet(j);

        if(enemy[x] == -1) {
            enemy[x] = y;
        } else {
            setFriends(enemy[x], y);
        }
        if(enemy[y] == -1) {
            enemy[y] = x;
        } else {
            setFriends(enemy[y], x);
        }

        return true;
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

    int n;
    cin >> n;

    UnionFind uf(n);

    int c,x,y;cin>>c>>x>>y;

    while(c!=0) {
        if(c==1) {
            if(!uf.setFriends(x, y)) {
                cout << -1 << '\n';
            }
        } else if(c==2){
            if(!uf.setEnemies(x, y)) {
                cout << -1 << '\n';
            }
        }else if(c==3) {
            cout << uf.areFriends(x, y) << '\n';
        }else {
            cout << uf.areEnemies(x, y) << '\n';
        }
        cin>>c>>x>>y;
    }

    return 0;
}