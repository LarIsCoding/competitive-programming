#include <iostream>
#include <stack>

using namespace std;

#define isOn(S, j) (S & (1 << j))        // checa se bit j é true
#define setBit(S, j) (S | = (1 << j))    // seta bit j para true
#define clearBit(S, j) (S &= ~(1 << j))  // seta bit j para false
#define toggleBit(S, j) (S ^= (1 << j))  // troca bit j de valor
#define lowBit(S) (S & (−S))             // checa o primeiro bit a partir da direita que é true, na forma de potencia de 2
#define setAll (S, n) (S = (1 << n) − 1) // seta todos os bit para true em um conjunto de tamanho n

void printSet(int vS) {
    printf("S = %2d = ", vS);
    stack<int> st;
    while(vS)
        st.push(vS % 2), vS /= 2;
    while (!st.empty())
        printf("%d ", st.top()), st.pop();
    printf("\n");
}

int main() {
    int S = 34;
    S = S << 1; // multiplica por 2
    S = S >> 2; // divide por 4 (2x2)

    return 0;
}