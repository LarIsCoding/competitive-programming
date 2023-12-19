#include <iostream>
#include <vector>
#include <stack>

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
    vector<ll> setSum;
    int numSets;
    ll maxSum;

    public:
    UnionFind(int N) {
        maxSum = (ll)0;
        setSize.assign(N, 0);
        setSum.assign(N, (ll)0);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++) 
            p[i] = i;
    }

    void activateSet(int i) {
        setSize[i] = 1;
        setSum[i] = (ll)a[i];
        maxSum = max(maxSum, (ll)a[i]);
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
            setSum[x] += setSum[y];
            maxSum = max(maxSum, setSum[x]);
        } else {
            p[x] = y;
            setSize[y] += setSize[x];
            setSum[y] += setSum[x];
            maxSum = max(maxSum, setSum[y]);
        }

        if(rank[x] == rank[y]) rank[y]++;
    }

    int numDisjointSets() {
        return numSets;
    }

    int sizeOfSets(int i) {
        return setSize[findSet(i)];
    }

    ll getMaxSum() {
        return maxSum;
    }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }

    UnionFind uf(n);

    stack<int> destroy;
    for(int i = 0;i<n;i++) {
        int aux;
        cin>>aux;aux--;
        destroy.push(aux);
    }

    stack<ll> res;
    while(!destroy.empty()){
        res.push(uf.getMaxSum());
        int d=destroy.top();destroy.pop();
        uf.activateSet(d);
        if(d - 1 >= 0 && uf.sizeOfSets(d-1) > 0) {
            uf.unionSet(d, d-1);
        }
        if(d + 1 < n && uf.sizeOfSets(d+1) > 0) {
            uf.unionSet(d, d+1);
        }
    }

    while(!res.empty()) {
        cout << res.top()<<endl;
        res.pop();
    }

    return 0;
}