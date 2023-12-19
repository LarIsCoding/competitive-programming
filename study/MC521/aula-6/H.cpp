#include <iostream>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int memo[1000000001];

bool testa(int x) {
    cout << x << endl;
    if(x < 0) return 0;
    if(memo[x] != -1) return memo[x];

    return memo[x] = testa(x - 11) || testa(x - 111) || testa(x - 1111) || testa(x - 11111)
        || testa(x - 111111) || testa(x - 1111111) || testa(x - 11111111) || testa(x - 111111111);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    memo[0] = 1;
    for(int i = 1; i < 1000000001; i++) {
        memo[i] = -1;
    }

    int t;
    cin >> t;

    while(t--) {
        int x;
        cin >> x;

        if(testa(x)) {
            cout << "YES\n";
        } else  {
            cout << "NO\n";
        }
    }

    return 0;
}