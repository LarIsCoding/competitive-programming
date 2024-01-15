#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<int> stops;

    int r, aux;
    cin >> r;

    for(int i = 0; i < r; i++) {
        cin >> aux;
        stops.insert(aux);
    }

    n--;

    while(n--) {
        cin >> r;
        set<int> newStops;

        for(int i = 0; i < r; i++) {
            cin >> aux;
            if(stops.find(aux) != stops.end()) {
                newStops.insert(aux);
            }
        }

        stops = newStops;
    }

    bool space = false;
    for(auto it = stops.begin(); it != stops.end(); it++) {
        if(space) cout << ' ';
        space = true;
        cout << *it;
    }
    cout << endl;
    return 0;
}