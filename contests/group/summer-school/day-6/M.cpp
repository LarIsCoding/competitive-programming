#include <iostream>
#include <cstring>
#include <vector>
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

    while(true) {
        cin >> s;
        if (s[0] == '*') break;

        int n = (int) s.length();
        vector<int> z = z_function(s, n);

        int k = 1;
        for (int i = n - 1; i >= 0; i--) {

            if(z[i] == n - i) {
                int passo = z[i];

                bool falhou = false;
                for (int d = i; d > 0; d = d - passo) {
                    if (z[d] != n - d) {
                        falhou = true;
                        break;
                    }
                }
                
                if (!falhou) {
                    k = n / passo;
                    break;
                }
            }
        }
        
        cout << k << endl;
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
