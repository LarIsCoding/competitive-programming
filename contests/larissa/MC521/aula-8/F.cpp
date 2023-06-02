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
        int n;
        cin >> n;

        string s;
        cin >> s;

        int num0 = 0, num1 = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') num0++;
            else num1++;
        }

        bool toggle = false;
        int acc = 0;

        for(int i = 0; i < n; i++) {

            if(s[i] == '0') {
                num0--;
                if(toggle && num1) {
                    acc++;
                    toggle = !toggle;
                }
            }
            else {
                num1--;
                if(!toggle && num0) {
                    acc++;
                    toggle = !toggle;
                }
            }
        }

        cout << acc << endl;
    }

    return 0;
}