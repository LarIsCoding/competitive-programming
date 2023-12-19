#include <bits/stdc++.h>

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

vector<pair<int, int> > adj[(int)1e5+5];
ll d[(int)1e5+5][2];
bool visited[(int)1e5+5][2];

void minPath(int src) {
    priority_queue<pair<pair<ll,bool>, int>, vector<pair<pair<ll,bool>, int> >, greater< pair<pair<ll,bool>, int> > > pq;
    pq.push(mp(mp(0,false),src));
    memset(visited,false,sizeof visited);

    while(!pq.empty()) {
        ll dist = pq.top().f.f;
        bool used = pq.top().f.s;
        int v = pq.top().s;
        pq.pop();
        
        if(used && visited[v][1]) continue;
        if(!used && visited[v][0]) continue;

        if(used) d[v][1]=dist;
        else d[v][0]=dist;

        if(used) visited[v][1]=true;
        else visited[v][0]=true;

        for(ii it:adj[v]) {
            if(used) pq.push(mp(mp(dist+(ll)it.s,true),it.f));
            else {
                pq.push(mp(mp(dist+(ll)it.s/2,true),it.f));
                pq.push(mp(mp(dist+(ll)it.s,false),it.f));
            }
        }
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >>n>>m;

    for(int i=0;i<m;i++) {
        int a,b,c;cin>>a>>b>>c;a--;b--;
        adj[a].push_back(mp(b,c));
    }

    minPath(0);

    cout<<min(d[n-1][0],d[n-1][1])<<endl;

    return 0;
}