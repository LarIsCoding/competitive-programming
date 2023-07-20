#include <iostream>
#include <math.h>
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

    double d, m;
    cin >> d>>m;

    double h = sqrt(2*d*d);

    int n = (int)(m / h);

    double x = n*(int)d;
    double y = (n%2) ? d : 0;
    int mul = (n%2) ? -1 : 1;

    double sobra = m - n * h;
    double anda = sqrt(sobra*sobra/(double)2);

    x+=anda;
    y+= mul*anda;

    cout << setprecision(10) << fixed << x << ' ' << y << endl;

    return 0;
}