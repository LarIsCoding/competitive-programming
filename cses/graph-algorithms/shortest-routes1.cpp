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
bool visited[(int)1e5+5];

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

    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
    pq.push(mp(0,0));
    memset(visited,false,sizeof visited);

    while(!pq.empty()) {
        ll dist = pq.top().f;
        ll v = pq.top().s;
        pq.pop();
        if(visited[v]) continue;
        d[v]=dist;
        visited[v]=true;

        for(ii it:adj[v]) {
            pq.push(mp(dist+(ll)it.s,it.f));
        }
    }

    bool space=false;
    for(int i=0;i<n;i++) {
        if(space)cout<<' ';
        space=true;
        cout<<d[i];
    }
    cout<<endl;

    return 0;
}