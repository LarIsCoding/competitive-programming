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

        string line1, line2;
        cin >> line1 >> line2;

        int acc = 0;
        bool found0 = false, found1 = false;

        for(int i = 0; i < n; i++) {
            bool u = line1[i] == '1';
            bool d = line2[i] == '1';

            if(u != d) {
                acc += 2;

                if(found0) acc++;

                found0 = false;
                found1 = false;

            } else if (!u) {
                if(found0) acc++;
                if(found1) acc += 2;
                else found0 = true;
                found1 = false;

            } else {
                if(found0) acc += 2;
                else found1 = true;
                found0 = false;
            }
        }

        if(found0) acc++;

        cout << acc << endl;
    }

    return 0;
}