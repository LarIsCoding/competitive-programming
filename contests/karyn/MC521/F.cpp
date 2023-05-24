#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    while (1){
    string s;
    getline(cin, s);
    if (s == "*") break;
    else{
        int n = s.size();
        int corretos = 0;
        double contador = 0;
        for (int i = 1; i<n; i++){
            if (s[i] == 'W') contador = contador + (1.00);
            if (s[i] == 'H') contador = contador + double(1.0/2);
            if (s[i] == 'Q') contador = contador + double(1.0/4);
            if (s[i] == 'E') contador = contador + double(1.0/8);
            if (s[i] == 'S') contador = contador + double(1.0/16);
            if (s[i] == 'T') contador = contador + double(1.0/32);
            if (s[i] == 'X') contador = contador + double(1.0/64);
            if (s[i] == '/') {
                if (contador == 1.00) corretos++;
                contador = 0;
            }
        }
        cout << corretos << endl;
    }
    }
    return 0;
}
