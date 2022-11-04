#include <iostream>

using namespace std;

#include <stack>

bool is_open(char c) {
    return (c == '{') || (c == '[') or (c == '(');
}

bool is_pair(char open, char close) {
    if ((open == '{') && (close == '}')) return true;
    if ((open == '[') && (close == ']')) return true;
    if ((open == '(') && (close == ')')) return true;
    return false;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    string a;
    
    for(int i = 0; i < t; i++) {
        cin >> a;

        stack<char> cadeia;
        cadeia.push('0');

        for(int i = 0; i < a.size(); i++) {
            if(is_open(a[i])) {
                cadeia.push(a[i]);
            } else {
                if(is_pair(cadeia.top(), a[i])) {
                    cadeia.pop();
                } else {
                    cadeia.push(a[i]);
                    break;
                }
            }
        }

        if(cadeia.top() == '0') {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}