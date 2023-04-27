#include <iostream>
#include <cmath>
#include <iomanip>

#define EPS 1e−9 // this value is adjustable; 1e−9 is usually small enough

using namespace std;

bool can(double f) {
    // Test number
    return true;
}

int main() {
    // binary search the answer
    double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;

    double diff = hi - lo;

    double eps = 1e-9; // this value is adjustable; 1e−9 is usually small enough

    while(fabs(diff) > eps) {

        mid = (lo + hi) / 2.0; // try the middle value

        if(can(mid)) {
            ans = mid;
            hi = mid;
        } // save the value, then continue
        else lo = mid;

        diff = hi - lo;
    }

    printf("%.3lf\n ", ans);
    cout << setprecision(3) << fixed << ans << endl;

    return 0;
}
