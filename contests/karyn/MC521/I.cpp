#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int W, N;
        cin >> W >> N;
        int distancia = 0;
        int peso = 0;
        int x, w;
        vector<int> xs;
        bool continuou = false;
        for (int j = 0; j < N; j++){
            cin >> x >> w;
            xs.push_back(x);
            if (continuou == false) distancia += x;
            else distancia += (x- xs[j-1]);
            if (peso + w == W){
                peso += w;
                distancia += x;
                peso = 0;
                continuou = false;}
            else if (peso + w > W)  {
                distancia += x; 
                continuou = false;
                peso = 0; 
                distancia += x; 
                if (w == W){
                    peso += w; 
                    distancia += x; 
                    peso = 0; 
                    continuou = false; 
                    }
                else{
                    peso += w; 
                    continuou = true;
                    }
                }
            else {
                peso += w;
                continuou = true;}
            if (j == N-1 && continuou == true) distancia+= x;
        }
        cout << distancia << endl;
    }
    return 0;
}
