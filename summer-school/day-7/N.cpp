#include <iostream>

using namespace std;

pair<int, int> getNumVowels(string s) {
    int min = 0;
    int max = 0;

    int n = s.length();
    for(int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'a' || c == 'A' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u') {
            min++;
            max++;
        } else if (c == 'y' || c == 'Y') {
            max++;
        }
    }

    return make_pair(min, max);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    string s1, s2, s3;
    pair<int, int> num;
    int a, b, c;

    for(int i = 0; i < t; i++) {
        cin >> a >> b >> c;
        getline(cin, s1);
        getline(cin, s1);
        getline(cin, s2);
        getline(cin, s3);

        num = getNumVowels(s1);
        if (num.first > 5 || num.second < 5) {
            cout << "NO" << endl;
            continue;
        }

        num = getNumVowels(s2);
        if (num.first > 7 || num.second < 7) {
            cout << "NO" << endl;
            continue;
        }

        num = getNumVowels(s3);
        if (num.first > 5 || num.second < 5) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}