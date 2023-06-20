#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

long double a[1505];
set<long double> combinations;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    long double x;
    cin >> n >> k >> x;

    long double sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+n);

    long double x_ = sum / (long double)n;

    long double bestX = x_;

    for(int i = 0; i < n; i++) {
        long double newX = (sum - a[i])/(n - 1);
        if(abs(newX - x) < abs(bestX - x)) {
            bestX = newX;
        }
    }

    if(k == 1) {
        cout << setprecision(20) << fixed << abs(bestX - x) << endl;
        return 0;
    }

    if(n == 2) {
        if(abs(bestX - x) > abs(0 - x)) {
            bestX = 0;
        }
        cout << setprecision(20) << fixed << abs(bestX - x) << endl;
        return 0;
    }

    long double target = sum - x * (n - 2);
    int l = 0, r = n - 1;

    while(l < r) {
        long double newX = (sum - a[l] - a[r])/(long double)(n - 2);
        if(abs(bestX - x) > abs(newX - x)) {
            bestX = newX;
        }

        long double diff = a[l] + a[r] - target;
        if(diff > 0) r--;
        else if(diff < 0) l++;
        else break;
    }

    if(k == 2) {
        cout << setprecision(20) << fixed << abs(bestX - x) << endl;
        return 0;
    }

    if(n == 3) {
        if(abs(bestX - x) > abs(0 - x)) {
            bestX = 0;
        }
        cout << setprecision(20) << fixed << abs(bestX - x) << endl;
        return 0;
    }

    target = sum - x * (n - 3);
    
    for(int i = 0; i < n; i++) {
        l = 0;
        r = n - 1;

        while(l < r) {
            if(l == i) {
                l++;
                continue;
            }
            if(r == i) {
                r--;
                continue;
            }

            long double newX = (sum - a[l] - a[r] - a[i])/(long double)(n - 3);
            if(abs(bestX - x) > abs(newX - x)) {
                bestX = newX;
            }

            long double diff = a[l] + a[r] + a[i] - target;
            if(diff > 0) r--;
            else if(diff < 0) l++;
            else break;
        }
    }

    if(k == 3) {
        cout << setprecision(20) << fixed << abs(bestX - x) << endl;
        return 0;
    }

    if(n == 4) {
        if(abs(bestX - x) > abs(0 - x)) {
            bestX = 0;
        }
        cout << setprecision(20) << fixed << abs(bestX - x) << endl;
        return 0;
    }

    target = sum - x * (n - 4);
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            long double left = target - a[i] - a[j];
            auto it = combinations.lower_bound(left);
            if(it != combinations.end()) {
                long double newX = (sum - a[i] - a[j] - *it)/(long double)(n - 4);
                if(abs(bestX - x) > abs(newX - x)) {
                    bestX = newX;
                }
            }
            if(it != combinations.begin()) {
                it--;
                long double newX = (sum - a[i] - a[j] - *it)/(long double)(n - 4);
                if(abs(bestX - x) > abs(newX - x)) {
                    bestX = newX;
                }
            }
        }
        for(int j = 0; j < i; j++) {
            combinations.insert(a[i] + a[j]);
        }
    }

    cout << setprecision(20) << fixed << abs(bestX - x) << endl;

    return 0;
}