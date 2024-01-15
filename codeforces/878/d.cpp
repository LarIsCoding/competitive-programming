#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int a[(int)2e5 + 5];

int maxTime(int l, int r) {
    return (a[r] - a[l] + 1)/2;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if(n <= 3) {
            cout << 0 << endl;
            continue;
        }

        sort(a, a+n);

        int p1 = 0, p2 = n - 2;

        bool mustContinue = true;
        while(mustContinue) {
            for(int i = 1; i < 3; i++) {
                int oldMaxMid = maxTime(p1 + 1, p2);
                int newMaxE = maxTime(0, p1 + 1);
                int newMaxD = maxTime(p2, n - 1);

                if(newMaxE <= newMaxD) {
                    if(newMaxE < oldMaxMid) {
                        p1++;
                    } else {
                        mustContinue = false;
                    }
                } else {
                    if(newMaxD < oldMaxMid) {
                        p2--;
                    } else {
                        mustContinue = false;
                    }
                }
            }
        }

        int max1 = maxTime(0, p1);
        int max2 = maxTime(p1 + 1, p2);
        int max3 = maxTime(p2 + 1, n - 1);

        cout << max(max1, max(max2, max3)) << endl;
    }

    return 0;
}