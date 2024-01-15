#include <iostream>
#include <stack>
#include <set>

using namespace std;

int MAX = (int)3e5 + 5;

set<int> adj[(int)3e5 + 5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    stack<int> road, snow;
    road.push(1);
    road.push(2);

    if(adj[2].find(1) == adj[2].end()) {
        stack<int> tmp = road;
        road = snow;
        snow = tmp;
    }

    for(int i = 3; i <= n; i++) {
        if(!road.empty() && road.top() == 1 && snow.empty()) {
            while(!road.empty()) {
                snow.push(road.top());
                road.pop();
            }
            stack<int> tmp = road;
            road = snow;
            snow = tmp;
        } else if(!road.empty() && road.top() == 1) {
            while(!snow.empty()) {
                road.push(snow.top());
                snow.pop();
            }
            stack<int> tmp = road;
            road = snow;
            snow = tmp;
        }
        if(snow.empty()) {
            if(adj[i].find(road.top()) != adj[i].end()) {
                road.push(i);
            } else {
                snow.push(i);
            }
        } else if(road.empty()) {
            if(adj[i].find(snow.top()) != adj[i].end()) {
                road.push(i);
                road.push(snow.top());
                snow.pop();
            } else {
                snow.push(i);
            }
        } else {
            if(adj[i].find(road.top()) != adj[i].end()) {
                road.push(i);
                if(adj[i].find(snow.top()) != adj[i].end()) {
                    road.push(snow.top());
                    snow.pop();
                }
            } else {
                snow.push(road.top());
                road.pop();
                if(!road.empty() && adj[i].find(road.top()) != adj[i].end()) {
                    road.push(i);
                } else {
                    snow.push(i);
                }
            }
        }
    }

    while(!snow.empty()) {
        road.push(snow.top());
        snow.pop();
    }

    if(road.top() != 1) {
        while(!road.empty()) {
            snow.push(road.top());
            road.pop();
        }

        stack<int> tmp = road;
        road = snow;
        snow = tmp;
    }

    cout << road.top();
    road.pop();

    while(!road.empty()) {
        cout << ' ' << road.top();
        road.pop();
    }
    cout << endl;

    return 0;
}