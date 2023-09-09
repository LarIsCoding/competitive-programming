#include <iostream>
#include <vector>
#include <map>
#include <cstring>

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

int presentes[(int)1e5+5];

int n, tin[100005], tout[100005], timer, up[22][100005], dist[100005];
vi v[100005], path; 

void dfs(int a,int p){
    timer++; tin[a]=timer; up[0][a]=p; dist[a]=1+dist[p];
    for(int i=1;i<22;i++) up[i][a]=up[i-1][up[i-1][a]];
    path.push_back(a);

    for(auto x : v[a]){
        if(x==p) continue;
        dfs(x,a);
    }

    timer++; tout[a]=timer;
    path.push_back(a);
}

int anc(int a,int b){
    return (tin[a]<=tin[b] && tout[b]<=tout[a]);
}

int lca(int a,int b){
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int i=21;i>=0;i--)
        if(!anc(up[i][a],b)) a=up[i][a];

    return up[0][a];
}

int upK(int a,int b){
    for(int i=21;i>=0;i--)
        if(b>=(1<<i)) b-=(1<<i), a=up[i][a];

    return a;
}

int quant[(int)1e5+5];
bool par[(int)1e5+5];
int num;

void remove(int idx) {
    int u=path[idx];
    par[u]=!par[u];
    if(par[u]) {
        if(quant[presentes[u]]==0) num++;
        quant[presentes[u]]++;
    } else {
        quant[presentes[u]]--;
        if(quant[presentes[u]]==0) num--;
    }
}
void add(int idx) {
    int u=path[idx];
    par[u]=!par[u];
    if(par[u]) {
        if(quant[presentes[u]]==0) num++;
        quant[presentes[u]]++;
    } else {
        quant[presentes[u]]--;
        if(quant[presentes[u]]==0) num--;
    }
}
int get_answer() {
    return num;
}

int block_size=448;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
        if(!anc(path[q.l],path[q.r])) {
            int l=lca(path[q.l],path[q.r]);
            int idx=tin[l];
            add(idx);
            answers[q.idx] = get_answer();
            remove(idx);
        }
    }
    return answers;
}

map<string,int> map_presentes;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    timer=-1;

    int index=0;
    for(int i=1;i<=n;i++) {
        string s;cin>>s;
        if(map_presentes.find(s)==map_presentes.end()) {
            map_presentes[s]=index;
            index++;
        }
        presentes[i]=map_presentes[s];
    }

    for(int i=0;i<n-1;i++) {
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(par,false,sizeof par);
    memset(quant,0,sizeof par);
    num=0;
    dfs(1,1);

    vector<Query> queries;

    for(int i=0;i<m;i++) {
        int a,b;cin>>a>>b;
        if(tin[b]<tin[a]) {
            swap(a, b);
        }
        Query q;
        if(anc(a,b)) {
            q = (Query){tin[a], tin[b], i};
        } else {
            q = (Query){tout[a], tin[b], i};
        }
        queries.push_back(q);
    }

    vector<int> res = mo_s_algorithm(queries);

    for(int i=0;i<m;i++) {
        cout << res[i] << endl;
    }

    return 0;
}