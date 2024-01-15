#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

#define NIL 0
#define INF (1<<28)
#define FORI(i, b) for(int i = 1; i <= b; i++)
#define all(v) v.begin(), v.end()

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

map<string,int> id;

set<set<int> > con;
map<set<int>, int> idCon;

#define isOn(S, j) (S & (1 << j))

struct BipMatcher {
  vector<vi> G;
  vi match, dist;
  int n, m, nm, ret;
  // n: number of nodes on left side, nodes are numbered 1 to n
  // m: number of nodes on right side, nodes are numbered n+1 to n+m
  // G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]
  BipMatcher(int n, int m):
    n(n), m(m), G(nm = n + m + 1), match(nm), dist(nm){}

  void AddEdge(int vl, int vr){
    G[vl].push_back(vr + n);
    G[vr + n].push_back(vl);
  }

  bool bfs() {
    queue<int> q;
    FORI(i, n)
      if(match[i] == NIL) {
        dist[i] = 0;
        q.push(i);
      }
      else 
        dist[i] = INF;

    dist[NIL] = INF;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(u != NIL)
        for(int v : G[u])
          if(dist[match[v]] == INF) {
            dist[match[v]] = dist[u] + 1;
            q.push(match[v]);
          }
    }
    return dist[NIL] != INF;
  }

  bool dfs(int u) {
    if(u != NIL) {
      for(int v : G[u])
        if(dist[match[v]] == dist[u] + 1) {
          if(dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
          }
        }
      dist[u] = INF;
      return false;
    }
    return true;
  }

  int Solve(bool reset = true) {
    if (reset) ret = 0, fill(all(match), NIL);

    while(bfs())
      FORI(i, n)
        if(match[i] == NIL && dfs(i))
          ret++;
    return ret;
  }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int index=0;
    for(int i=0;i<n;i++) {
        int a;cin>>a;
        vector<int> v;

        for(int j=0;j<a;j++) {
            string s;cin>>s;
            if(!id.count(s)) {
                id[s]=index;
                index++;
            }
            v.push_back(id[s]);
        }

        for(int j=1;j<pow(2,a);j++) {
            set<int> c;
            for(int k=0;k<a;k++) {
                if(isOn(j,k)) {
                    c.insert(v[k]);
                }
            }
            con.insert(c);
        }
    }

    index=1;
    for(auto it:con) {
        idCon[it]=index;
        index++;
    }

    BipMatcher bip(con.size(), con.size());

    for(auto it:con) {
        if(it.size()==1) continue;
        int id1=idCon[it];
        vi aux;
        for(int it2:it) {
            aux.push_back(it2);
        }
        for(int it2:aux) {
            it.erase(it2);
            int id2=idCon[it];
            bip.AddEdge(id1, id2);
            it.insert(it2);
        }
    }

    cout << con.size()-bip.Solve() << endl;

    return 0;
}