#include <iostream>
#include <queue>

using namespace std;

int main() {
   // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> children;

    for(int i = 1; i <= n; i++) {
        children.push(i);
    }

    if(!children.empty()) {
        children.push(children.front());
        children.pop();
        cout << children.front();
        children.pop();
    }

    while(!children.empty()) {
        children.push(children.front());
        children.pop();
        cout << ' ' << children.front();
        children.pop();
    }
    cout << '\n';

    return 0;
}