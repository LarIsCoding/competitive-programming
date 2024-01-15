#include <iostream>
#include <stack>

using namespace std;

int imp[2][101];

void printAnswer(int n) {

    int index;

    if(imp[0][n] == -1) {
       index = 1;
    } else if(imp[1][n] == -1) {
        index = 0;
    } else {
        if(imp[0][n] <= imp[1][n]) {
            index = 0;
        } else {
            index = 1;
        }
    }

    stack<char> r;

    for(int i = n; i > 0; i--) {
        if(index == 0) r.push('B');
        else r.push('R');

        if(imp[!index][i - 1] == imp[index][i]) {
            index = !index;
        }
    }

    while(!r.empty()) {
        cout << r.top();
        r.pop();
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

        imp[0][0] = 0;
        imp[1][0] = 0;

        for(int i = 1; i <= n; i++) {
            char aux;
            cin >> aux;

            if(aux == 'R') {
                if(imp[0][i - 1] == -1) imp[1][i] = imp[1][i - 1] + 1;
                else if(imp[1][i - 1] == -1) imp[1][i] = imp[0][i - 1];
                else imp[1][i] = min(imp[0][i - 1], imp[1][i - 1] + 1);
                imp[0][i] = -1;

            } else if(aux == 'B') {
                if(imp[1][i - 1] == -1) imp[0][i] = imp[0][i - 1] + 1;
                else if(imp[0][i - 1] == -1) imp[0][i] = imp[1][i - 1];
                else imp[0][i] = min(imp[1][i - 1], imp[0][i - 1] + 1);
                imp[1][i] = -1;

            } else {
                if(imp[1][i - 1] == -1) {
                    imp[1][i] = imp[0][i - 1];
                    imp[0][i] = imp[0][i - 1] + 1;
                }
                else if(imp[0][i - 1] == -1) {
                    imp[0][i] = imp[1][i - 1];
                    imp[1][i] = imp[1][i - 1] + 1;
                }
                else {
                    int newImpB = min(imp[1][i - 1], imp[0][i - 1] + 1);
                    imp[1][i] = min(imp[0][i - 1], imp[1][i - 1] + 1);
                    imp[0][i] = newImpB;
                }
            }
        }

        printAnswer(n);
    }

    return 0;
}