#include <iostream>
#include <stack>

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

    int a,b; cin >>a>>b;

    stack<int> s;
    s.push(b);

    while(b > a) {
        if(b%2) {
            b--;
            if(b%10) break;
            b /= 10;
        } else {
            b /= 2;
        }
        s.push(b);
    }

    if(a == b) {
        cout << "YES\n";
        cout << s.size() << endl;

        bool sep = false;
        while(!s.empty()) {
            if(sep) cout << ' ';
            cout << s.top();
            s.pop();
            sep = true;
        }
        cout << endl;
    } else {
        cout << "NO\n";
    }

    return 0;
}