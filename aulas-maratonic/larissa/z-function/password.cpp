#include <iostream>

using namespace std;
#include <vector>

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

    int max_z = 0;
    int z_final = 0;
    for(int i = 1; i < z.size(); i++) {
        if((z.size() - z[i]) == i) {
            if(z[i] <= max_z) {
                z_final = z[i];
                break;
            }
            max_z = max(max_z, z[i] - 1);
        } else {
            max_z = max(max_z, z[i]);
        }
    }

    if(z_final == 0) {
        cout << "Just a legend\n";
    } else {
        for(int i = 0; i < z_final; i++) {
            cout << s[i];
        }
        cout << "\n";
    }

    return 0;
}