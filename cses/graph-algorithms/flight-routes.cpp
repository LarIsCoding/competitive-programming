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

int n,k;
vector<pair<int, int> > adj[(int)1e5+5];
vector<ll> d[(int)1e5+5];
bool visited[(int)1e5+5];

void minPath(int src) {
    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
    pq.push(mp(0,src));
    memset(visited,false,sizeof visited);
    vector<ll> r;

    while(!pq.empty()) {
        ll dist = pq.top().f;
        ll v = pq.top().s;
        pq.pop();

        if(visited[v]) continue;

        d[v].push_back(dist);
        if(d[v].size()==k) visited[v]=true;

        for(ii it:adj[v]) {
            int u=it.first;
            int w=it.second;

            if(visited[u]) continue;
            pq.push(mp(dist+(ll)w,u));
        }
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >>n>>m>>k;

    for(int i=0;i<m;i++) {
        int a,b,c;cin>>a>>b>>c;a--;b--;
        adj[a].push_back(mp(b,c));
    }

    minPath(0);

    bool space=false;
    for(ll it:d[n-1]) {
        if(space)cout<<' ';
        space=true;
        cout<<it;
    }
    cout<<endl;

    return 0;
}