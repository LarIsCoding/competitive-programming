#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

string words[200000];

void troca(set<string> jaFoi, int maior, int menor, char comeca, char termina, int n) {
    int troca = ceil((double)(maior - (menor + 1))/(double)2);
    vector<int> indices;

    for(int i = 0; i < n && troca; i++) {
        string aux = words[i];
        if(aux[0] == comeca) continue;
        if(aux[0] == termina && aux[aux.size() - 1] == termina) continue;

        reverse(aux.begin(), aux.end());
        if(jaFoi.find(aux) == jaFoi.end()) {
            troca--;
            indices.push_back(i + 1);
        }
    }

    if(troca) {
        cout << -1 << endl;
        return;
    }

    cout << indices.size() << endl;

    bool espaco = false;
    for(int i = 0; i < indices.size(); i++) {
        if(espaco) cout << ' ';
        else espaco = true;
        cout << indices[i];
    }
    cout << endl;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> words[i];
        }
        
        int comeca0termina0 = 0, comeca0termina1 = 0, comeca1termina0 = 0, comeca1termina1 = 0;
        set<string> comeca0, comeca1;

        for(int i = 0; i < n; i++) {

            char first = words[i][0];
            char last = words[i][words[i].size() - 1];

            if(first == '0' && last == '0') comeca0termina0++;
            if(first == '1' && last == '1') comeca1termina1++;

            if(first == '0' && last == '1') {
                comeca0termina1++;
                comeca0.insert(words[i]);
            }
            if(first == '1' && last == '0') {
                comeca1termina0++;
                comeca1.insert(words[i]);
            }
        }

        if(comeca0termina0 > 0 && comeca1termina1 > 0 && comeca0termina1 == 0 && comeca1termina0 == 0) {
            cout << -1 << endl;
            continue;
        }

        if(comeca0termina1 > comeca1termina0 + 1) {
            troca(comeca1, comeca0termina1, comeca1termina0, '1', '0', n);
        } else if(comeca1termina0 > comeca0termina1 + 1) {
            troca(comeca0, comeca1termina0, comeca0termina1, '0', '1', n);
        } else {
            cout << 0 << endl << endl;
        }
    }

    return 0;
}