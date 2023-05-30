#include <iostream>

using namespace std;
typedef long long int ll;

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int memo[30][200005];
string s;
string newS;

int dp(char last, int index, int n) {
    if(memo[last - 'a'][index] != -1) return memo[last - 'a'][index];

    if(index == n) return memo[last - 'a'][index] = 0;

    if(s[index] < last) {
        return memo[last - 'a'][index] = 1 + dp(last, index + 1, n);
    }

    int op1 = 1 + dp(last, index + 1, n);
    int op2 = dp(s[index], index + 1, n);

    return memo[last - 'a'][index] = min(op1, op2);
}

void recupera(char last, int index, int n) {
    if(index == n) return;
    if(s[index] < last) {
        newS[index] = last;
        return recupera(last, index + 1, n);
    }
    if(dp(last, index, n) == dp(s[index], index + 1, n)) {
        return recupera(s[index], index + 1, n);
    }
    newS[index] = last;
    return recupera(last, index + 1, n);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cin >> s;
    newS = s;

    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 200005; j++) {
            memo[i][j] = -1;
        }
    }

    cout << dp('a', 0, n) << endl;
    recupera('a', 0, n);
    cout << newS << endl;

    return 0;
}