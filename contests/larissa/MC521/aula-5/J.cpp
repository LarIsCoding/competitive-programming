#include <iostream>
#include <math.h>

using namespace std;

string mapInput[20010];
char mapOutput[201][201];

void printDimmension(int x) {
    cout << ' ';
    if(x < 100) {
        cout << ' ';
    }
    if(x < 10) {
        cout << ' ';
    }
    cout << x;
}

pair<int, int> transform(int i, int j, int c) {
    int pos = (i * c) + j;
    return make_pair(pos / 50, pos % 50);
}

int convertFromB(int rl, int rr, int cl, int cr, int c, int index) {
    pair<int, int> coord = transform(rl, cl, c);
    char target = mapInput[coord.first][coord.second];

    for(int i = rl; i <= rr; i++) {
        for(int j = cl; j <= cr; j++) {

            coord = transform(i, j, c);
            if(mapInput[coord.first][coord.second] == target) continue;

            cout << 'D';
            index++;
            if(index == 50) {
                cout << endl;
                index = 0;
            }

            int rm = (rl + rr) / 2;
            int cm = (cl + cr) / 2;
            
            index = convertFromB(rl, rm, cl, cm, c, index);
            if(cm < cr) {
                index = convertFromB(rl, rm, cm + 1, cr, c, index);
            }
            if(rm < rr) {
                index = convertFromB(rm + 1, rr, cl, cm, c, index);
            }
            if(rm < rr && cm < cr) {
                index = convertFromB(rm + 1, rr, cm + 1, cr, c, index);
            }
            return index;
        }
    }

    cout << target;
    index++;
    if(index == 50) {
        cout << endl;
        index = 0;
    }
    return index;
}

void convertFromD(int rl, int rr, int cl, int cr) {
    char aux;
    cin >> aux;

    if(aux == 'D') {
        int rm = (rl + rr) / 2;
        int cm = (cl + cr) / 2;
        
        convertFromD(rl, rm, cl, cm);
        if(cm < cr) convertFromD(rl, rm, cm + 1, cr);
        if(rm < rr) convertFromD(rm + 1, rr, cl, cm);
        if(cm < cr && rm < rr) convertFromD(rm + 1, rr, cm + 1, cr);
        return;
    }

    for(int x = rl; x <= rr; x++) {
        for(int y = cl; y <= cr; y++) {
            mapOutput[x][y] = aux;
        }
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    char type;
    int r, c;

    cin >> type;

    while(type != '#') {
        cin >> r >> c;

        if(type == 'B') {
            cout << 'D';
            printDimmension(r);
            printDimmension(c);
            cout << endl;

            int n = ceil((double)(r * c) / (double)50);

            for(int i = 0; i < n; i++) {
                cin >> mapInput[i];
            }

            convertFromB(0, r - 1, 0, c - 1, c, 0);
            cout << endl;
        } else {
            cout << 'B';
            printDimmension(r);
            printDimmension(c);
            cout << endl;

            convertFromD(0, r - 1, 0, c - 1);
            int acc = 0;
            for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++) {
                    if(acc == 50) {
                        cout << endl;
                        acc = 0;
                    }
                    cout << mapOutput[i][j];
                    acc++;
                }
            }
            cout << endl;
        }

        cin >> type;
    }

    return 0;
}