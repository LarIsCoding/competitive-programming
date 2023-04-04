#include <bits/stdc++.h>
#include <string.h>
#include <map>
using namespace std;

int ganhador(int p1, int p2, string m1, string m2){
    map <string, int> codigo;
    codigo["scissors"] = 1;
    codigo["rock"] = 3;
    codigo["paper"] = 7;
    int soma = codigo[m1] + codigo[m2];
    if (soma == 6 || soma == 2 || soma == 14) return 0;
    else if (soma == 4){
        if (m1 == "rock") return p1;
        else return p2;
    }
    else if (soma == 10){
        if (m1 == "paper") return p1;
        else return p2;
    }
    else { //soma == 8
        if (m1 == "scissors") return p1;
        else return p2;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n, k;
    bool first = true;
    while(cin >> n && n!=0){
        cin >> k;
        int partidas_validas = k*n*(n-1)/2;
        map <int, int> w;
        for (int i = 1; i <= n; i++) w[i] = 0;
        map <int, int> l;
        for (int i = 1; i <= n; i++) l[i] = 0;
        int p1, p2;
        string m1, m2;
        for (int i = 0; i < k*n*(n-1)/2; i++){
            cin >> p1 >> m1 >> p2 >> m2;
            int resultado = ganhador(p1, p2, m1, m2);
            if (resultado == p1) {
                w[p1]++;
                l[p2]++;
            }
            else if (resultado == p2) {
                w[p2]++;
                l[p1]++;
            }
            else partidas_validas--;
        }
        if (first == false) cout << endl;
        if (partidas_validas != 0) for (int i = 1; i <=n; i++) cout << fixed << setprecision(3) << double(w[i])/(w[i]+l[i]) << endl;
        else for (int i = 1; i <=n; i++) cout << "-" << endl;
        first = false;
    }
    return 0;
}
