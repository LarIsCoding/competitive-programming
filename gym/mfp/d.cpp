#include <iostream>
#include <iomanip>

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

    long double m1, m2, x1, x2, f;
    cin >>m1>>m2>>x1>>x2>>f;
    long double d = abs(x2-x1);
    long double g = f * (d*d)/(m1*m2);

    cout << setprecision(10) << fixed << g << endl;

    return 0;
}