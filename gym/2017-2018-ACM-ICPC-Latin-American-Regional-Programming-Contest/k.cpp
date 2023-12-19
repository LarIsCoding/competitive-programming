#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

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

char grid[20][20];
map<ii, int> id1,id2;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r,c;
    cin >> r>>c;

    int size1=0;
    int size2=0;

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin>>grid[i][j];
            if((i+j)%2==0) {
                size1++;
                id1[mp(i,j)]=size1;
                if(grid[i][j]=='-') {
                    size1++;
                }
            } else {
                size2++;
                id2[mp(i,j)]=size2;
                if(grid[i][j]=='-') {
                    size2++;
                }
            }
        }
    }

    BipMatcher bip(size1,size2);

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if((i+j)%2==1) continue;
            ii viz[4]={
                mp(i-1,j),
                mp(i+1,j),
                mp(i,j-1),
                mp(i,j+1),
            };
            for(int k=0;k<4;k++) {
                if(viz[k].f<0||viz[k].f>=r||viz[k].s<0||viz[k].s>=c) continue;
                bip.AddEdge(id1[mp(i,j)],id2[viz[k]]);
                if(grid[i][j]=='-') {
                    bip.AddEdge(id1[mp(i,j)]+1,id2[viz[k]]);
                }
                if(grid[viz[k].f][viz[k].s]=='-') {
                    bip.AddEdge(id1[mp(i,j)],id2[viz[k]]+1);
                    if(grid[i][j]=='-') {
                        bip.AddEdge(id1[mp(i,j)]+1,id2[viz[k]]+1);
                    }
                }
            }
        }
    }

    int x=bip.Solve();
    if(x==size1&&x==size2) cout<<"Y\n";
    else cout<<"N\n";

    return 0;
}