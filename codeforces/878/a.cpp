#include <iostream>
#include <stack>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

string s;
stack<char> answer;

bool find(int index, int n) {
    if(index == n) return true;
    for(int i = index + 1; i < n; i++) {
        if(s[i] == s[index]) {
            if(find(i + 1, n)) {
                answer.push(s[index]);
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        cin >> s;

        find(0, n);

        while(!answer.empty()) {
            cout << answer.top();
            answer.pop();
        }
        cout << endl;
    }

    return 0;
}