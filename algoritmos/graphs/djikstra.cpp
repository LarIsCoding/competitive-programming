int n, m;
ll dist[MAXN];
vector< ii > v[MAXN];
priority_queue<ii, vector<ii>, greater<ii> > p;

void dijkstra(int ini){
    for(int i=0;i<=n;i++) dist[i]=linf;
    
    dist[ini]=0; p.push({0,ini});
    while(!p.empty()){
        int a; ll d;
        a=p.top().s; d=p.top().f; p.pop();
        
        if(d>dist[a]) continue;
        for(auto x : v[a]){
            if(dist[x.f]>x.s+dist[a]){
                dist[x.f]=x.s+dist[a];
                p.push({dist[x.f],x.f});
            }
        }
    }
}