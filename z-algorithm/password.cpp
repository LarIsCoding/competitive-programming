#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> z = z_function(s);

    int maximo_z = 0;
    for(int i = 0; i < z.size(); i++) {
        if (z[i] <= maximo_z) {
            continue;
        }
        int ini = z.size() - z[i];
        if (z[i] == z.size() - i) {
            ini++;
        }
        for (int j = ini; j < z.size(); j++) {
            int dist = z.size() - j;
            if (dist <= maximo_z) {
                break;
            }
            if (z[j] == dist) {
                maximo_z = max(maximo_z, dist);
                break;
            }
        }
    }

    if (maximo_z == 0) {
        cout << "Just a legend\n";
    } else {
        for (int i = 0; i < maximo_z; i++) {
            cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}