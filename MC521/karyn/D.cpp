#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    while(cin >> n && n != 0){
        int Ti=1, Ni=2, Wi=3, Ei=4, Si=5, Bi=6;
        int T, N, W, E, S, B;
        for (int i = 0; i < n; i++){
            string direcao;
            cin >> direcao;
            if (direcao == "south"){
                T=Ni; N=Bi; S=Ti; B=Si;
                Ti = T; Ni = N; Si = S; Bi = B;
            }
            if (direcao == "north"){
                T=Si; N=Ti; S=Bi; B=Ni;
                Ti = T; Ni = N; Si = S; Bi = B;
            }
            if (direcao == "west"){
                T=Ei; E=Bi; W=Ti; B=Wi;
                Ti = T; Ei = E; Wi = W; Bi = B;
            }
            if (direcao == "east"){
                T=Wi; E=Ti; W=Bi; B=Ei;
                Ti = T; Ei = E; Wi = W; Bi = B;
            }
        }
        cout << Ti << endl;
    }
    return 0;
}
