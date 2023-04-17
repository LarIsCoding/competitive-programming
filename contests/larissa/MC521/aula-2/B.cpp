#include <iostream>
#include <set>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    while(a != 0 || b != 0) {
        set<int> cartasA, cartasB;
        int aux;

        for(int i = 0; i < a; i++) {
            cin >> aux;
            cartasA.insert(aux);
        }

        for(int i = 0; i < b; i++) {
            cin >> aux;
            cartasB.insert(aux);
        }

        set<int>::iterator itA = cartasA.begin(), itB = cartasB.begin();
        int totalA = 0, totalB = 0;
        while(itA != cartasA.end() || itB != cartasB.end()) {
            if(itA == cartasA.end()) {
                totalB++;
                itB++;
            } else if(itB == cartasB.end()) {
                totalA++;
                itA++;
            }
            else if(*itA == *itB) {
                itA++; itB++;
            } else if(*itA < *itB) {
                totalA++;
                itA++;
            } else {
                totalB++;
                itB++;
            }
        }

        cout << min(totalA, totalB) << endl; 
        cin >> a >> b;
    }

    return 0;
}