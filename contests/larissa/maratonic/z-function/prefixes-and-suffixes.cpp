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
    z[0] = z.size();

    int quantidade[z.size() + 1];
    for(int i = 0; i < z.size() + 1; i++) {
        quantidade[i] = 0;
    }

    bool is_suffix[z.size() + 1];
    for(int i = 0; i < z.size() + 1; i++) {
        is_suffix[i] = false;
    }

    for(int i = z.size() - 1; i >= 0; i--) {
        if((z.size() - i) == z[i]) {
            is_suffix[z[i]] = true;
        }
        quantidade[z[i]]++;
    }

    int num = 0;
    int acc = 0;
    for(int i = z.size(); i > 0; i--) {
        int aux = quantidade[i];
        quantidade[i] += acc;
        acc += aux;
        if(is_suffix[i]) {
            num++;
        }
    }

    cout << num << '\n';
    for(int i = 1; i < z.size() + 1; i++) {
        if (is_suffix[i]) {
            cout << i << ' ' << quantidade[i] << '\n';
        }
    }

    return 0;
}