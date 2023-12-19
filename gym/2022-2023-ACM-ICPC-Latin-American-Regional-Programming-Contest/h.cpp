#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
#include <map>

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

map<int,string> name;
map<string,int> id;

int adj[605][605];
#define V 605

int ans[305];

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
	// Create a visited array and mark all vertices as not
	// visited
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	// Create a queue, enqueue source vertex and mark source
	// vertex as visited
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	// Standard BFS Loop
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				// If we find a connection to the sink node,
				// then there is no point in BFS anymore We
				// just have to set its parent and can return
				// true
				if (v == t) {
					parent[v] = u;
					return true;
				}
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	// We didn't reach sink in BFS starting from source, so
	// return false
	return false;
}

int n;

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;

	// Create a residual graph and fill the residual graph
	// with given capacities in the original graph as
	// residual capacities in residual graph
	int rGraph[V]
			[V]; // Residual graph where rGraph[i][j]
				// indicates residual capacity of edge
				// from i to j (if there is an edge. If
				// rGraph[i][j] is 0, then there is not)
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V]; // This array is filled by BFS and to
				// store path

	int max_flow = 0; // There is no flow initially

	// Augment the flow while there is path from source to
	// sink
	while (bfs(rGraph, s, t, parent)) {
		// Find minimum residual capacity of the edges along
		// the path filled by BFS. Or we can say find the
		// maximum flow through the path found.
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

        ans[parent[t]-n]=parent[parent[t]];

		// update residual capacities of the edges and
		// reverse edges along the path
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		// Add path flow to overall flow
		max_flow += path_flow;
	}

	// Return the overall flow
	return max_flow;
}

int limit[305];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        string s;cin>>s;
        id[s]=i;
        name[i]=s;
    }

    memset(adj,0,sizeof adj);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            adj[i][n+j]=1;
        }
    }
    for(int i=0;i<n;i++) {
        adj[2*n][i]=1;
        adj[n+i][2*n+1]=1;
    }

    int r;cin>>r;
    bool used[305];

    for(int i=0;i<r;i++) {
        int m,w;cin>>m>>w;
        memset(used, false, sizeof used);

        for(int j=0;j<m;j++) {
            string s;cin>>s;
            used[id[s]]=true;
            limit[id[s]]=max(w-1,limit[id[s]]);
        }

        for(int i=0;i<n;i++) {
            if(!used[i]) adj[i][n+w-1]=0;
        }
    }

    for(int i=0;i<n;i++) {
        for(int k=0;k<limit[i];k++) {
            adj[i][n+k]=0;
        }
    }

    fordFulkerson(adj,2*n,2*n+1);

    for(int i=0;i<n;i++) {
        if(i>0) cout<<' ';
        cout<<name[ans[i]];
    }
    cout<<endl;

    return 0;
}