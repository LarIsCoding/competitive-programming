#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int m[105];
bool isBig[105];

bool test(int x, int n) {
    vb used;
    used.assign(105, false);

    int last = 0;
    int lastShort = 0;
    int lastShortId = 0;

    for(int i = 1; i <= n+1; i++) {
        if(isBig[i]) {
            if(m[i] - last <= x) {
                last = m[i];
                continue;
            }
            if(m[i] - lastShort <= x) {
                used[lastShortId] = true;
                last = m[i];
            }
            return false;
        } else {
            if(m[i] - last <= x) {
                lastShort = m[i];
                lastShortId = i;
                continue;
            } if(lastShort > last && m[i] - lastShort <= x) {
                last = lastShort;
                used[lastShortId] = true;
                lastShort = m[i];
                lastShortId = i;
            }
            return false;
        }
    }

    last = m[n+1];
    lastShort = m[n+1];
    lastShortId = n+1;

    for(int i = n; i >= 0; i--) {
        if(isBig[i]) {
            if(abs(m[i] - last) <= x) {
                last = m[i];
                continue;
            }
            if(abs(m[i] - lastShort) <= x) {
                if(used[lastShortId]) return false;
                last = m[i];
            }
            return false;
        } else {
            if(abs(m[i] - last) <= x) {
                lastShort = m[i];
                lastShortId = i;
                continue;
            } if(lastShort < last && abs(m[i] - lastShort) <= x) {
                last = lastShort;
                if(used[lastShortId]) return false;
                lastShort = m[i];
                lastShortId = i;
            }
            return false;
        }
    }
    return true;
}

int findMaxLeap(int l, int r, int n) {
    if(l == r) return l;

    int m = (l+r+1)/2;

    if(test(m, n)) {
        return findMaxLeap(m, r, n);
    }
    return findMaxLeap(l, m - 1, n);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, d;
        cin >> n >> d;

        for(int i = 1; i <= n; i++) {
            char s, aux;
            cin >> s >> aux >> m[i];
            isBig[i] = s == 'B';
        }
        m[0] = 0;
        isBig[0] = true;
        m[n+1] = d;
        isBig[n+1] = true;

        cout << findMaxLeap(1, 1000000000, n) << endl;
    }

    return 0;
}