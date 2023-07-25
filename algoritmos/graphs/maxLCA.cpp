int n, tin[200005], tout[200005], t, up[22][200005], mup[22][200005];
vector<ii> v[200005];

void dfs(int a,int p,int w){
    tin[a]=t++; up[0][a]=p; mup[0][a]=w;
    
    for(int i=1;i<=20;i++) up[i][a]=up[i-1][up[i-1][a]], mup[i][a]=max(mup[i-1][a],mup[i-1][up[i-1][a]]);

    for(auto b : v[a]) if(b.f!=p) dfs(b.f,a,b.s);

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
    if(c==a) return got(b,a);
    if(c==b) return got(a,b);

    return max(got(a,c),got(b,c));
}