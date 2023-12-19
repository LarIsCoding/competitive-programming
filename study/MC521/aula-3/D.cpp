#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef long long int ll;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int m, n;
        cin >> m >> n;

        queue<int> presents, list;
        set<int> removed;

        for(int i = 0; i < m; i++) {
            int aux;
            cin >> aux;
            presents.push(aux);
        }

        for(int i = 0; i < n; i++) {
            int aux;
            cin >> aux;
            list.push(aux);
        }

        ll tempo = 0;
        while(!list.empty()) {
            int next = list.front();
            list.pop();

            if(removed.find(next) != removed.end()) {
                tempo++;
                removed.erase(next);
                continue;
            }

            tempo += 2 * removed.size();

            while(presents.front() != next) {
                tempo += 2;
                removed.insert(presents.front());
                presents.pop();
            }
            tempo++;
            presents.pop();
        }

        cout << tempo << endl;
    }

    return 0;
}