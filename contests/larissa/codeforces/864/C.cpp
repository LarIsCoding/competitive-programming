#include <iostream>

using namespace std;

bool tryCombination(int r, int c, int r1, int c1, int r2, int c2, int r3, int c3) {
    if(!(r == r1 && c <= c1) || (r <= r1 && c == c1)) return false;
    if(!(r == r2 && c >= c2) || (r <= r2 && c == c2)) return false;
    if(!(r == r3 && c <= c3) || (r >= r3 && c == c3)) return false;
    return true;
}

pair<int, int> getPoint(int r1, int c1, int r2, int c2, int r3, int c3) {
    if(tryCombination(r1, c2, r1, c1, r2, c2, r3, c3)) return make_pair(r1, c2);
    if(tryCombination(r1, c3, r1, c1, r2, c2, r3, c3)) return make_pair(r1, c3);
    if(tryCombination(r2, c1, r1, c1, r2, c2, r3, c3)) return make_pair(r2, c1);
    if(tryCombination(r2, c3, r1, c1, r2, c2, r3, c3)) return make_pair(r2, c3);
    if(tryCombination(r3, c1, r1, c1, r2, c2, r3, c3)) return make_pair(r3, c1);
    return make_pair(r3, c2);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, m, dist1, dist2, dist3;
        cin >> n >> m;
        cout << "? 1 1\n";
        cin >> dist1;
        cout << "? 1 " << m << endl;
        cin >> dist2;
        cout << "? " << n << " 1\n";
        cin >> dist3;

        int r1 = 1 + dist1;
        int c1 = 1 + dist1;

        int r2 = 1 + dist2;
        int c2 = n - dist2;

        int r3 = m - dist3;
        int c3 = 1 + dist3;

        pair<int, int> result = getPoint(r1, c1, r2, c2, r3, c3);
        cout << "! " << result.first << ' ' << result.second << endl;
    }

    return 0;
}