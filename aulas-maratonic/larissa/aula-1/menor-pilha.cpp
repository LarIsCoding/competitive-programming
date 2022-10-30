#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int INF = numeric_limits<int>::max();

int find_min(vector<int> s) {
    int minimun = INF;
    for(vector<int>::iterator it = s.begin(); it != s.end(); ++it) {
        minimun = min(minimun, *it);
    }
    return minimun;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<int> s;

    cin >> n;

    int minimun = INF;

    for(int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if(operation[1] == 'U') {
            int v;
            cin >> v;
            s.push_back(v);
            minimun = min(minimun, v);
        } else if(operation[1] == 'O') {
            if(s.empty()) {
                cout << "EMPTY" << endl;
                continue;
            }
            if(s.back() == minimun) {
                minimun = INF;
            }
            s.pop_back();
        } else {
            if(minimun == INF) {
                minimun = find_min(s);
            }
            if(minimun == INF) {
                cout << "EMPTY" << endl;
            } else {
                cout << minimun << endl;
            }
        }
    }

    return 0;
}