#include <iostream>
#include <map>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string composition;
    cin >> composition;

    map<char, int> valor;
    valor['W'] = 64;
    valor['H'] = 32;
    valor['Q'] = 16;
    valor['E'] = 8;
    valor['S'] = 4;
    valor['T'] = 2;
    valor['X'] = 1;

    while(composition != "*") {
        int sum = 0;
        int count = 0;
        for(int i = 1; i < composition.length(); i++) {
            if(composition[i] == '/') {
                if(sum == 64) count++;
                sum = 0;
                continue;
            }
            sum += valor[composition[i]];
        }
        cout << count << endl;
        cin >> composition;
    }

    return 0;
}