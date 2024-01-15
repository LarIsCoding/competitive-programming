#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;

        stack<int> diamantes;

        int sum = 0;

        for(int j = 0; j < input.size(); j++) {
            if(input[j] == '<') {
                diamantes.push('<');
            } else if(input[j] == '>') {
                if(!diamantes.empty() && diamantes.top() == '<') {
                    sum++;
                    diamantes.pop();
                }
            }
        }

        cout << sum << endl;
    }

    return 0;
}