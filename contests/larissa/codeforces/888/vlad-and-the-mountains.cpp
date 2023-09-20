#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int h[(int)2e5+5];
bool visited[(int)2e5+5];
ii hOrd[(int)2e5+5];

int n, tin[200005], tout[200005], t, up[22][200005], mup[22][200005];
vector<int> v[200005],adj[200005];

class UnionFind {

    private:
    vi p, rank, setSize, wasProcessed;
    int numSets;

    public:
    UnionFind(int N) {
        wasProcessed.assign(N, false);
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

    void setProcessed(int i) {
        wasProcessed[findSet(i)]=true;
    }

    bool hasProcessed(int i) {
        return wasProcessed[findSet(i)];
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

bool cmp(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}

void dfs(int a,int p,int w){
    tin[a]=t++; up[0][a]=p; mup[0][a]=w;
    
    for(int i=1;i<=20;i++) up[i][a]=up[i-1][up[i-1][a]], mup[i][a]=max(mup[i-1][a],mup[i-1][up[i-1][a]]);

    for(auto b : v[a]) if(b!=p) dfs(b,a,h[b]);

    tout[a]=t++;
}

bool anc(int a,int b){
    return (tin[a]<=tin[b] && tout[b]<=tout[a]);
}

int lca(int a,int b){
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int i=20;i>=0;i--)
        if(!anc(up[i][a],b)) a=up[i][a];

    return up[0][a];
}

int got(int a,int b){
    int resp=-inf;
    
    for(int i=20;i>=0;i--)
        if(!anc(up[i][a],b)){ resp=max(resp,mup[i][a]); a=up[i][a];}

    return max(resp,mup[0][a]);
}

int getBig(int a,int b){
    if(a==b) return 0;
    int c=lca(a,b);
    if(c==a) return max(h[c],got(b,a));
    if(c==b) return max(h[c],got(a,b));

    return max(h[c], max(got(a,c),got(b,c)));
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;

    while(test--) {
        int m;cin>>n>>m;

        for(int i=0;i<n;i++) {
            cin>>h[i];
            hOrd[i].f=h[i];
            hOrd[i].s=i;
            visited[i]=false;
        }

        vector<Edge> edges;
        UnionFind uf(n);

        for(int i=0;i<m;i++) {
            int a,b;cin>>a>>b;a--;b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        sort(hOrd, hOrd+n);

        priority_queue<pair<ii,ii>,vector<pair<ii,ii> >, greater<pair<ii,ii> > > pq;

        for(int i=0;i<n;i++) {
            if(visited[hOrd[i].s]) continue;
            pq.push(mp(mp(-1,hOrd[i].f),mp(hOrd[i].s,-1)));

            while(!pq.empty()) {
                pair<ii,ii> top=pq.top();pq.pop();
                if(visited[top.s.f]) continue;
                // cout<<"it:"<<top.s.f+1<<' '<<top.s.s+1<<endl;
                visited[top.s.f]=true;
                if(top.s.s!=-1 && !uf.isSameSet(top.s.f, top.s.s)) {
                    v[top.s.f].push_back(top.s.s);
                    v[top.s.s].push_back(top.s.f);
                    uf.unionSet(top.s.f, top.s.s);
                    // cout<<"add: "<<top.s.f+1 << ' '<< top.s.s+1<<endl;
                }
                for(int u:adj[top.s.f]) {
                    // cout<<u+1<<endl;
                    pq.push(mp(mp(h[top.s.f],h[u]),mp(u,top.s.f)));
                }
            }
        }

        t=0;
        int q;cin>>q;

        while(q--) {
            int a,b,e;cin>>a>>b>>e;a--;b--;
            if(!uf.isSameSet(a,b)) {
                cout << "NO\n";
                continue;
            }
            if(!uf.hasProcessed(a)) {
                uf.setProcessed(a);
                dfs(a,a,h[a]);
            }
            int r = getBig(a,b);
            if(r-h[a]>e) cout << "NO\n";
            else cout<<"YES\n";
        }

        if(test>0) cout<<endl;

        for(int i=0;i<n;i++) {
            v[i].clear();
            adj[i].clear();
        }
    }

    return 0;
}