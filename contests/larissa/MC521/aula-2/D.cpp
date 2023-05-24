#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while(n != 0) {
        int top = 1;
        int north = 2;
        int west = 3;

        string direction;
        for(int i = 0; i < n; i++) {
            cin >> direction;

            if(direction == "north") {
                int lastNorth = north;
                north = top;
                top = 7 - lastNorth;
            } else if(direction == "south") {
                int lastTop = top;
                top = north;
                north = 7 - lastTop;
            } else if(direction == "east") {
                int lastTop = top;
                top = west;
                west = 7 - lastTop;
            } else {
                int lastWest = west;
                west = top;
                top = 7 - lastWest;
            }
        }

        cout << top << endl;
        cin >> n;
    }

    return 0;
}