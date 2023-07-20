#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int num[(int)2e5+10];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i <n;i++) {
        cin >> num[i];
    }

    sort(num, num+n);

    int m = 0;
    for(int i = 0; i < n/2; i++) {
        m = max(m, (num[i] + num[n-1-i])/2);
    }

    cout << m << endl;

    return 0;
}