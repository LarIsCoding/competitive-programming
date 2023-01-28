#include <bits/stdc++.h>

using namespace std;

bool canGoToPos(char *mapa[], int i, int j, int n, int m) {
    if(i < 0 || i >= n || j < 0 || j >= m || mapa[i][j] == 'M' || mapa[i][j] == 'P') return false;
    return true;
}

void printaMatrix(char *mapa[], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

void pintaMonstro(char *mapa[], bool *mapaM[], int i, int j, int n, int m, int falta) {

    if(i < 0 || i >= n || j < 0 || j >= m || falta == 0 || mapaM[i][j] == true) return;

    mapa[i][j] = 'M';
    mapaM[i][j] = true;

    pintaMonstro(mapa, mapaM, i - 1, j, n, m, falta - 1);
    pintaMonstro(mapa, mapaM, i + 1, j, n, m, falta - 1);
    pintaMonstro(mapa, mapaM, i, j - 1, n, m, falta - 1);
    pintaMonstro(mapa, mapaM, i, j + 1, n, m, falta - 1);
}

int findMinPath(char *mapa[], pair<int, int> ini, pair<int, int> fim, int n, int m) {
    if (mapa[ini.first][ini.second] == 'M' || mapa[fim.first][fim.second] == 'M') return -1;


    queue<pair<pair<int, int>, int> > q;
    int i, j, time;

    q.push(make_pair(ini, 0));

    while(!q.empty()) {
        pair<pair<int, int>, int> prox = q.front();
        q.pop();
        i = prox.first.first;
        j = prox.first.second;
        time = prox.second;

        if(i < 0 || i >= n || j < 0 || j >= m || mapa[i][j] == 'M') continue;

        if(mapa[i][j] == 'F') return time;
        if(mapa[i][j] == 'P') continue;
        mapa[i][j] = 'P';

        if(canGoToPos(mapa, i - 1, j, n, m)) {
            q.push(make_pair(make_pair(i - 1, j), time + 1));
        }
        if(canGoToPos(mapa, i + 1, j, n, m)) {
            q.push(make_pair(make_pair(i + 1, j), time + 1));
        }
        if(canGoToPos(mapa, i, j - 1, n, m)) {
            q.push(make_pair(make_pair(i, j - 1), time + 1));
        }
        if(canGoToPos(mapa, i, j + 1, n, m)) {
            q.push(make_pair(make_pair(i, j + 1), time + 1));
        }
    }

    return -1;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, d;
    cin >> n >> m >> d;

    char **mapa;
    mapa = new char *[n];
    for(int i = 0; i < n; i++)
        mapa[i] = new char[m];

    queue<pair<int, int>> monsters;
    pair<int, int> ini;
    pair<int, int> fim;

    char item;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> item;
            mapa[i][j] = item;
            if(item == 'M') {
                monsters.push(make_pair(i, j));
            }
            if(item == 'S') {
                ini = make_pair(i, j);
            }
            if(item == 'F') {
                fim = make_pair(i, j);
            }
        }
    }

    if (d > 0) {
        pair<int, int> pos;
        while(!monsters.empty()) {
            bool **mapaM;
            mapaM = new bool *[n];
            for(int i = 0; i < n; i++) {
                mapaM[i] = new bool[m];
                for(int j = 0; j < m; j++) {
                    mapaM[i][j] = false;
                }
            }

            pos = monsters.front();
            monsters.pop();

            pintaMonstro(mapa, mapaM, pos.first, pos.second, n, m, d + 1);
        }
    }

    cout << findMinPath(mapa, ini, fim, n, m) << endl;

    return 0;
}
