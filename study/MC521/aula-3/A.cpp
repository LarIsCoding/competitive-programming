#include <iostream>
#include <stack>
#include <set>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        stack<int> sequence;

        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            sequence.push(x);
        }

        set<int> num;
        int acc = 0;
        while(!sequence.empty()) {
            if(num.find(sequence.top()) != num.end()) break;
            acc++;
            num.insert(sequence.top());
            sequence.pop();
        }

        cout << n - acc << endl;
    }

    return 0;
}