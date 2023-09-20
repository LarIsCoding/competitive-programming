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
ll d[(int)1e5+5];
ll numVezes[(int)1e5+5];
bool visited[(int)1e5+5];
int minPath[(int)1e5+5];
int maxPath[(int)1e5+5];

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

    priority_queue<pair<ll,ii>, vector<pair<ll,ii> >, greater<pair<ll,ii> > > pq;
    pq.push(mp(0,mp(0,-1)));
    memset(visited,false,sizeof visited);
    memset(numVezes,0,sizeof numVezes);
    numVezes[0]=1;
    minPath[0]=0;
    maxPath[0]=0;

    while(!pq.empty()) {
        ll dist = pq.top().f;
        ll v = pq.top().s.f;
        ll p = pq.top().s.s;
        pq.pop();

        if(visited[v]) {
            if(d[v]==dist) {
                numVezes[v]=(numVezes[v]+numVezes[p])%mod;
                minPath[v]=min(minPath[v],minPath[p]+1);
                maxPath[v]=max(maxPath[v],maxPath[p]+1);
            }
            continue;
        }
        
        d[v]=dist;
        visited[v]=true;
        if(p!=-1) {
            numVezes[v]=numVezes[p];
            minPath[v]=minPath[p]+1;
            maxPath[v]=maxPath[p]+1;
        }

        for(ii it:adj[v]) {
            pq.push(mp(dist+(ll)it.s,mp(it.f,v)));
        }
    }

    cout<<d[n-1]<<' '<<numVezes[n-1]<<' '<<minPath[n-1]<<' '<<maxPath[n-1]<<endl;

    return 0;
}