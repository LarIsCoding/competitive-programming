#include <iostream>
#include <set>

using namespace std;

typedef multiset<int> si;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        si reports;
        int aux, acc = 0;

        for(int i = 0; i < n; i++) {
            cin >> aux;
            si::iterator it = reports.upper_bound(aux);
            acc += distance(reports.begin(), it);
            reports.insert(aux);
        }

        cout << acc << endl;
    }

    return 0;
}