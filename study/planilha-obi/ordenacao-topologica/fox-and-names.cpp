#include <iostream>
#include <vector>

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

#define UNVISITED 2
#define PROCESSING 3
#define VISITED 1

vi dfs_num;
vector<vi> AdjList;
vi topoSort;

bool dfs(int u) {
    dfs_num[u] = PROCESSING;
    for(int j = 0; j < (int) AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if(dfs_num[v] == UNVISITED)
            dfs(v);
        if(dfs_num[v] == PROCESSING)
            return false;
    } 
    dfs_num[u] = VISITED;
    topoSort.push_back(u);
    return true;
}

string words[100];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin>>n;

    for(int i=0;i<n;i++) {
        cin>>words[i];
    }

    int v=26;
    AdjList.resize(v);

    for(int i=0;i<n-1;i++) {
        for(int j=0;j<words[i].size();j++) {
            if(j==words[i+1].size()) {
                cout << "Impossible\n";
                return 0;
            }
            char c1=words[i][j];
            char c2=words[i+1][j];
            if(c1 != c2) {
                AdjList[c1-'a'].push_back(c2-'a');
                break;
            }
        }
    }

    dfs_num.assign(v, UNVISITED);
    topoSort.clear();

    for(int i = 0; i < v; i ++) {
        if(dfs_num[i] == UNVISITED) {
            if(!dfs(i)) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    reverse(topoSort.begin(), topoSort.end());

    for(int i=0;i<v;i++) {
        cout<< (char)(topoSort[i]+'a');
    }
    cout<<endl;

    return 0;
}