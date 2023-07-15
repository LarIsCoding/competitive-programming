#include <iostream>
#include <iomanip>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

double x1,x2,y1,y2;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;

    while(t--) {
        cin >> x1>>y1>>x2>>y2;
        double a = (y2-x2*y1/x1)/(x2*x2-x1*x2);
        double b = (y1-a*x1*x1)/x1;
        double x = -b/a;
        cout << setprecision(10) << fixed << x<<endl;
    }

    return 0;
}