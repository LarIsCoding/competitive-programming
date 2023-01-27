#include <bits/stdc++.h>

using namespace std;

int isPalindrome(string s, int l, int r, bool removed) {
    if (l >= r) {
        return l + 1;
    }
    if (s[l] == s[r]) {
        return isPalindrome(s, l + 1, r - 1, removed);
    }
    if (removed) {
        return -1;
    }
    if (isPalindrome(s, l, r - 1, true) != -1)  {
        return r + 1;
    }
    if (isPalindrome(s, l + 1, r, true) != -1) {
        return l + 1;
    }
    return -1;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int len = s.length();

    int r = isPalindrome(s, 0, len - 1, false);
    if (r == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << r << endl;
    }

    return 0;
}
