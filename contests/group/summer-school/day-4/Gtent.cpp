#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <set>
using namespace std;

int main() {
    std::string s,sub;
    char c;
    cin >> s;
    int q, comando, pos, l, r, len;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> comando;
        if (comando  == 1){
            cin >> pos >> c;
            s[pos-1] = c;
        }
        else{
            cin >> l >> r;
            sub = s.substr(l - 1, r - l + 1);
            int a = r - l + 1;
            int inic = l - 1;
            set <char> conjunto;
            len = sub.length();
            for (int m = 0; m < len; m++){
                conjunto.insert(sub[m]);
            }
            int n = conjunto.size();
            cout << n << endl;
        }
    }
    return 0;
}
