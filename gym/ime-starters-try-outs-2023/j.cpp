#include <iostream>
#include <tgmath.h>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

typedef pair<long double,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

vector<ii> adj[(int)1e5+5];
vi visited;

long double log_a_to_base_b(long double a, long double b) {
    return log2(a) / log2(b);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n>>m;

    for(int i =0;i<m;i++) {
        int a,b,c;cin>>a>>b>>c;
        adj[a].push_back(mp(log_a_to_base_b(c, 7),b));
        adj[b].push_back(mp(log_a_to_base_b(c, 7),a));
    }

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(mp(0, 1));
    visited.assign((int)1e5+5, false);

    while(pq.top().second!=n) {
        int v = pq.top().second;
        long double c = pq.top().first;
        pq.pop();
        if(visited[v]) continue;
        visited[v]=true;
        for(auto it : adj[v]) {
            long double cost = c + it.first;
            pq.push(mp(cost, it.second));
        }
    }

    cout << setprecision(20) << fixed << pq.top().first << endl;

    return 0;
}