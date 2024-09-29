#include<bits/stdc++.h>

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
#define EPS 1e-9

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

int main()
{
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    vector<vector<int> > adj(n + 1);
    int ma = m;
    while (ma--) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int best = 0;
    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n + 1 , false);
        queue<pair<int, int> > qii;
        qii.push(mp(i, 0));
        while (!qii.empty()) {
            int v = qii.front().first;
            if (visited[v]) {
                qii.pop();
                continue;
            }
            for (auto j : adj[v]) {
                qii.push(mp(j, qii.front().second + 1));
            }
            best = max(qii.front().second, best);
            visited[v] = true;
            qii.pop();
        }
    }
    int final = 2*d  + 1 - best;
    printf("%d %d\n", final, final);
}