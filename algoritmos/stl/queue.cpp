#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;

    q.push(4);
    q.push(7);
    q.pop();

    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.empty() << endl;

   return 0;
}