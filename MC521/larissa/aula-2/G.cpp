#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))

void printSet(int vS) {
    printf("S = %2d = ", vS);
    stack<int> st;

    while(vS)
        st.push(vS % 2), vS /= 2;
    while(!st.empty())
        printf("%d", st.top()), st.pop();
    printf("\n");
}

int findMaxRook(int m, int n) {
    return min(m, n);
}

int findMaxKnight(int m, int n) {
    return ceil((double)m/(double)2) * ceil((double)n/(double)2) + (m/2) * (n/2);
}

int findMaxKing(int m, int n) {
    return ceil((double)m/(double)2) * ceil((double)n/(double)2);
}

void preenche(int i, int j, int m, int n, int board[]) {
    if(i >= 0 && i < m && j >= 0 && j < n)
        setBit(board[i], j);
}

int findMaxQueen(int m, int n, int row, int board[]) {
    if(row == m) return 0;
    int maior = 0;
    bool achou = false;

    for(int i = 0; i < n; i++) {
        if(!isOn(board[row], i)) {
            achou = true;

            int newBoard[m];
            for(int i = 0; i < m; i++) {
                newBoard[i] = board[i];
            }

            setBit(newBoard[row], i);
            for(int j = 1; j < max(m, n); j++) {
                preenche(row, i + j, m, n, newBoard);
                preenche(row, i - j, m, n, newBoard);
                preenche(row + j, i, m, n, newBoard);
                preenche(row - j, i, m, n, newBoard);
                preenche(row + j, i + j, m, n, newBoard);
                preenche(row - j, i - j, m, n, newBoard);
            }
            maior = max(maior, findMaxQueen(m, n, row + 1, newBoard));
        }
    }
    if(achou) maior++;
    return maior;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        char peca;
        int m, n;
        cin >> peca >> m >> n;

        if(peca == 'r') cout << findMaxRook(m, n) << endl;
        if(peca == 'k') cout << findMaxKnight(m, n) << endl;
        if(peca == 'K') cout << findMaxKing(m, n) << endl;
        if(peca == 'Q') {
            int board[m];
            for(int i = 0; i < m; i++) {
                board[i] = 0;
            }
            cout << findMaxQueen(m, n, 0, board) << endl;
        }
    }

    return 0;
}