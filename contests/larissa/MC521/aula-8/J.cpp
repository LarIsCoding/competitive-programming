#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

pair<double, double> c[10];

int fat(int x) {
    if(x == 1) return 1;
    return x * fat(x - 1);
}

double dist(pair<double, double> a, pair<double, double> b) {
    double distX = b.first - a.first;
    double distY = b.second - a.second;
    return sqrt(distX*distX + distY*distY);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int index = 1;

    while(n != 0) {
        for(int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            c[i] = mp(x, y);
        }

        double best = (double)inf;
        pair<double, double> bestPermutation[10];

        for(int i = 0; i < fat(n); i++) {
            double acc = 0;
            for(int j = 0; j < n - 1; j++) {
                acc += dist(c[j], c[j + 1]) + 16;
            }
        
            if(acc < best) {
                best = acc;
                for(int j = 0; j < n; j++) {
                    bestPermutation[j] = c[j];
                }
            }

            next_permutation(c, c + n);
        }

        cout << "**********************************************************\n";
        cout << "Network #" << index << endl;
        for(int j = 0; j < n - 1; j++) {
            pair<int, int> from = bestPermutation[j], to = bestPermutation[j + 1];
            cout << "Cable requirement to connect (";
            cout << from.first << ',' << from.second << ") to (" << to.first << ',' << to.second << ") is ";
            cout << fixed << setprecision(2) << dist(from, to) + 16 << " feet.\n";
            bestPermutation[j] = c[j];
        }
        cout << "Number of feet of cable required is ";
        cout << fixed << setprecision(2) << best << ".\n";

        cin >> n;
        index++;
    }

    return 0;
}