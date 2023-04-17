#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s;
    cin >> s;
    char c;
    long long q, i, a, k;
    cin >> q;
    for (long long g = 0; g < q; g++){
        cin >> i >> a >> k >> c;
        for (long long p  = 0; p <= k; p++){
            long long j = i + p*a;
            s[j-1] = c;
        }
    }
    cout << s;
    return 0;
}
