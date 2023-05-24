#include <bits/stdc++.h>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n_A, n_B;
    std::set<int> s1, s2;
    while (1) {
    s1.clear();
    s2.clear();
    cin >> n_A >> n_B;
    for (int i = 0; i < n_A; i++) {
        int n;
        cin >> n;
        s1.insert(n);
    } for (int i = 0; i < n_B; i++) {
        int n;
        cin >> n;
        s2.insert(n);
    }
    if (n_A == 0 && n_B == 0) break;
    std::set<int> result1, result2;
    result1.clear();
    result2.clear();
    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
        std::inserter(result1, result1.end()));
    std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(),
        std::inserter(result2, result2.end()));
    int p = min(result1.size(), result2.size());
    cout << p << endl;
    }
    return 0;
}
