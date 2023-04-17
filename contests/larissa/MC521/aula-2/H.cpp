#include <iostream>
#include <iomanip>

using namespace std;

pair<int, int> cmp(string m1, string m2) {
    if(m1 == m2) return make_pair(0, 0);
    if(m1 == "rock" && m2 == "scissors") return make_pair(1, 0);
    if(m1 == "paper" && m2 == "rock") return make_pair(1, 0);
    if(m1 == "scissors" && m2 == "paper") return make_pair(1, 0);
    return make_pair(0, 1);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n;

    bool printa = false;

    while(n != 0) {
        if(printa) cout << endl;

        cin >> k;

        int p1, p2;
        string m1, m2;

        pair<int, int> placar[n + 1];
        for(int i = 1; i < n + 1; i++) {
            placar[i] = make_pair(0, 0);
        }

        int total = (k * n * (n - 1))/2;

        for(int i = 0; i < total; i++) {
            cin >> p1 >> m1 >> p2 >> m2;

            pair<int, int> resultado;

            resultado = cmp(m1, m2);
            placar[p1].first += resultado.first;
            placar[p1].second += resultado.second;

            resultado = cmp(m2, m1);
            placar[p2].first += resultado.first;
            placar[p2].second += resultado.second;
        }

        for(int i = 1; i < n + 1; i++) {
            int win = placar[i].first;
            int lose = placar[i].second;

            if(win == 0 && lose == 0) {
                cout << "-\n";
            } else {
                double average = (double)win / (double)(win + lose);
                cout << fixed << setprecision(3) << average << endl;
            }
        }

        cin >> n;
        printa = true;
    }

    return 0;
}