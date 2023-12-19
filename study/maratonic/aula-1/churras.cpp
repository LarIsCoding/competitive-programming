#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
   return a.second < b.second;
}


int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(!cin.eof()) {
        int n;
        vector<pair<string, int> > carnes;

        cin >> n;

        for (int i = 0; i < n; i++) {
            string carne;
            int validade;

            cin >> carne >> validade;

            carnes.push_back(make_pair(carne, validade));
        }

        sort(carnes.begin(), carnes.end(), comp);

        for(int i = 0; i < n; i++) {
            cout << carnes[i].first;
            if(i != n - 1) {
                cout << ' ';
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}