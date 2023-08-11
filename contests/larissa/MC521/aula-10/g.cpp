#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;

    while(v!=0) {
        vi adj[305];
        int a, b;cin>>a>>b;

        while(a != 0 && b != 0) {
            adj[a].push_back(b);
            adj[b].push_back(a);
            cin>>a>>b;
        }

        vi cor(305, -1);
        queue<int> q;
        q.push(1);
        cor[1] = 0;
        bool isBipartitie = true;

        while(!q.empty() && isBipartitie) {
            int v = q.front(); q.pop();
            for(auto it : adj[v]) {
                if(cor[it] == -1) {
                    cor[it] = 1 - cor[v];
                    q.push(it);
                } else {
                    if(cor[it] == cor[v]) {
                        isBipartitie = false;
                        break;
                    }
                }
            }
        }

        if(isBipartitie) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        cin >> v;
    }

    return 0;
}