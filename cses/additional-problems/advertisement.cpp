#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;
typedef pair<int, int> ii;

int k[(int)2e5 + 5];
int proxMenor[(int)2e5 + 5];
int antMenor[(int)2e5 + 5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }

    stack<ii> s;

    for(int i = 0; i < n; i++) {
        while(!s.empty() && k[i] < s.top().first) {
            proxMenor[s.top().second] = i;
            s.pop();
        }

        s.push(make_pair(k[i], i));
    }

    while(!s.empty()) {
        proxMenor[s.top().second] = n;
        s.pop();
    }

    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && k[i] < s.top().first) {
            antMenor[s.top().second] = i;
            s.pop();
        }

        s.push(make_pair(k[i], i));
    }

    while(!s.empty()) {
        antMenor[s.top().second] = -1;
        s.pop();
    }

    ll maior = 0;
    for(int i = 0; i < n; i++) {
        ll r = (ll)k[i] * (ll)(proxMenor[i] - antMenor[i] - 1);
        maior = max(r, maior);
    }

    cout << maior << endl;

    return 0;
}