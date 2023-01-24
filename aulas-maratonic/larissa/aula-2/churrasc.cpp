#include <iostream> 
using namespace std;
#include <queue>

class Compare {
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.first > b.first;
    }
};

int main(){
    int m, k;
    cin >> m >> k;
    
    while (m != 0 && k != 0) {
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> fila;
        for (int j = 0; j < k - 1; j++) {
            int nota;
            cin >> nota;
            fila.push(make_pair(nota, j));
        }
        
        for (int j = k - 1; j < m; j++) {
            
            int nota;
            cin >> nota;
            fila.push(make_pair(nota, j));
            
            while (fila.top().second < j + 1 - k) {
                fila.pop();
            }
            
            cout << fila.top().first;
            if (j != m - 1) {
                cout << ' ';
            }
        }
        cout << '\n';

        cin >> m >> k;
    }

    return 0;
}