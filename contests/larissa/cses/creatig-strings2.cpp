#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int fat(int n) {
    if(n == 1 || n == 0) {
        return 1;
    }
    return n * fat(n - 1);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int numChar[26];
    for(int i = 0; i < 26; i++) {
        numChar[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        char in;
        cin >> in;
        numChar[in - 'a']++;
    }



    return 0;
}