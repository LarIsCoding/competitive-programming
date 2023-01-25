#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, a, b;
    cin >> n >> k;

    map<int, int> numbers; 
    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        if (numbers.find(a) == numbers.end()) {
            numbers[a] = 0;
        }

        numbers[a] += b;
    }

    int acc = 0;
    int find = -1;
    for (map<int, int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        acc += it->second;
        if (acc >= k) {
            find = it->first;
            break;
        }
    }

    cout << find << endl;

    return 0;
}
