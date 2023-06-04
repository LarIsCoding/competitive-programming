#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int a, b, p;
        string s;
        cin >> a >> b >> p;
        cin >> s;

        int i = s.size() - 2;
        int lastI = s.size() - 1;
        bool streakA = false, streakB = false;

        while(i >= 0 && p > 0) {
            if(s[i] == 'A') {
                streakA = true;
                if(streakB) {
                    p -= b;
                    if(p >= 0) {
                        lastI = i + 1;
                    }
                    streakB = false;
                }
            } else {
                streakB = true;
                if(streakA) {
                    p -= a;
                    if(p >= 0) {
                        lastI = i + 1;
                    }
                    streakA = false;
                }
            }
            i--;
        }

        p -= (s[0] == 'A') ? a : b;
        if(p >= 0) {
            lastI = 0;
        }

        cout << lastI + 1 << endl;
    }

    return 0;
}