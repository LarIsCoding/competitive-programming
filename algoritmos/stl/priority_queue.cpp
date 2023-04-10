#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int> > minPq;

    pq.push(100);
    pq.push(34);

    int result = pq.top();
    pq.pop();

    return 0;
}