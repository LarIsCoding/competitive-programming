vector<pair<int, int> > adj[(int)1e5+5];
ll d[(int)1e5+5];
bool visited[(int)1e5+5];

void minPath(int src) {
    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
    pq.push(mp(0,src));
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
}