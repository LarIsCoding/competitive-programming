#include <iostream>
#include <vector>
#include <queue>

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

vector<vector<char> > grid;
vector<vector<int> > dT,d1,d2;
vector<vector<bool> > visited;

int n,m;

void bfs(int x, int y, vector<vector<int> > &dist) {
    priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;
    pq.push(mp(0,mp(x,y)));

    while(!pq.empty()) {
        pair<int, ii> top=pq.top();pq.pop();
        int i=top.s.f;
        int j=top.s.s;

        if(visited[i][j]) continue;
        visited[i][j]=true;

        int add=(grid[i][j]=='.') ? 1:0;
        int d=top.f+add;

        dist[i][j]=d;

        ii pos[4] = {
            mp(i - 1, j),
            mp(i + 1, j),
            mp(i, j+1),
            mp(i, j-1),
        };

        for(int k=0;k<4;k++) {
            if(pos[k].f<0||pos[k].f>=n||pos[k].s<0||pos[k].s>=m) continue;
            pq.push(mp(d,mp(pos[k].f,pos[k].s)));
        }
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    grid.resize(n);
    dT.resize(n);
    d1.resize(n);
    d2.resize(n);
    visited.resize(n);

    for(int i=0;i<n;i++) {
        grid[i].resize(m);
        dT[i].resize(m);
        d1[i].resize(m);
        d2[i].resize(m);
        visited[i].assign(m,false);
    }

    int x,y,x1,y1,x2,y2;

    x1=-1;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='T') {
                x=i;
                y=j;
            } else if(grid[i][j]=='*' && x1==-1) {
                x1=i;
                y1=j;
            } else if(grid[i][j]=='*') {
                x2=i;
                y2=j;
            }
        }
    }

    bfs(x,y,dT);
    for(int i=0;i<n;i++) {
        visited[i].assign(m,false);
    }
    bfs(x1,y1,d1);
    for(int i=0;i<n;i++) {
        visited[i].assign(m,false);
    }
    bfs(x2,y2,d2);

    int best=inf;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int r=dT[i][j]+d1[i][j]+d2[i][j];
            if(grid[i][j]=='.')r-=2;
            best=min(best,r);
        }
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout<<d2[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    cout<<best<<endl;

    return 0;
}