#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
vector<int> z_function(string s, int n) {
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int contador;
    while (1){
        cin >> s;
        if (s[0] == '*') break;
        else{
            //cout << "analisando s: " << s << endl;
            int n = (int) s.length();
            vector<int> z = z_function(s, n);
            //cout << "conteúdo do vector v1 : \n";
                //for (vector<int>::iterator it = z.begin();
                   // it != z.end(); it++) {
                     //   cout << *it << " "; // valor na posição apontada por it
                    //}
               // cout << endl;
            for (int i = n-1; i >= 0; i--){
                int contador = 0;
                if(z[i] != 0 && z[i] == n-i){
                    int passo = z[i];
                    //cout << "passo: " << passo << endl;
                    contador = 1;
                    for (int d = i; d - passo > 0; d = d - passo){
                        if (z[d-passo] != 0 && z[d-passo]%passo == 0) {
                            contador++; }
                        else {
                            contador = -1;
                            break; }
                    }
                    //cout << contador << endl;
                    if (contador != -1) {
                        cout << contador+1 << endl;
                        break;
                    }
                }
                if (contador == 0  && i == 0) cout << 1 << endl;        
            } //f   
        }
    }
    return 0;
}


//imprimindo vetor
//cout << "conteúdo do vector v1 : \n";
              //  for (vector<int>::iterator it = z.begin();
               //     it != z.end(); it++) {
                 //       cout << *it << " "; // valor na posição apontada por it
                   // }
                    //cout << endl;
