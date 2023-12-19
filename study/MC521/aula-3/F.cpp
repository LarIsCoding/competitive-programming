#include <iostream>

using namespace std;

int getValue(string grid[3], int i, int j) {
    if(i >= 0 && i < 3 && j >= 0 && j < 3) {
        return (int)(grid[i][j] - '0');
    }
    return 0;
}

bool isZero(string grid[3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[i][j] == '1') return false;
        }
    }
    return true;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string grid[3];

        cin >> grid[0];
        cin >> grid[1];
        cin >> grid[2];

        string newGrid[3];
        newGrid[0] = grid[0];
        newGrid[1] = grid[1];
        newGrid[2] = grid[2];

        int count = -1;

        while(!isZero(grid)) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    int acc = 0;
                    acc += getValue(grid, i - 1, j);
                    acc += getValue(grid, i + 1, j);
                    acc += getValue(grid, i, j - 1);
                    acc += getValue(grid, i, j + 1);
                    newGrid[i][j] = (char)(acc % 2) + '0';
                }
            }

            grid[0] = newGrid[0];
            grid[1] = newGrid[1];
            grid[2] = newGrid[2];

            count++;
        }

        cout << count << endl;
    }

    return 0;
}