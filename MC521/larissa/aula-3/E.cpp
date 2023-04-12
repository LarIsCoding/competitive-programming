#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int getPoints(set<string> player, set<string> opponent1, set<string> opponent2) {
    int points = 0;
    set<string> onepoint, threepoint;

    set_difference(player.begin(), player.end(), opponent1.begin(), opponent1.end(), inserter(onepoint, onepoint.end()));
    points += onepoint.size();
    onepoint.clear();

    set_difference(player.begin(), player.end(), opponent2.begin(), opponent2.end(), inserter(onepoint, onepoint.end()));
    points += onepoint.size();

    set_difference(onepoint.begin(), onepoint.end(), opponent1.begin(), opponent1.end(), inserter(threepoint, threepoint.end()));
    points += threepoint.size();

    return points;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        set<string> player1, player2, player3;
        string aux;

        for(int j = 0; j < n; j++) {
            cin >> aux;
            player1.insert(aux);
        }

        for(int j = 0; j < n; j++) {
            cin >> aux;
            player2.insert(aux);
        }

        for(int j = 0; j < n; j++) {
            cin >> aux;
            player3.insert(aux);
        }

        int pointsPlayer1 = getPoints(player1, player2, player3);
        int pointsPlayer2 = getPoints(player2, player1, player3);
        int pointsPlayer3 = getPoints(player3, player1, player2);
        cout << pointsPlayer1 << ' ' << pointsPlayer2 << ' ' << pointsPlayer3 << endl;
    }

    return 0;
}
