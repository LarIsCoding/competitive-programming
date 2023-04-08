#include <iostream>
#include <queue>

using namespace std;

int main() {
    deque<int> dq;
    
    dq.push_back(4);
    dq.push_front(7);

    cout << dq.back() << endl;
    cout << dq.front() << endl;
    cout << dq.empty() << endl;

    dq.pop_back();
    dq.pop_front();

   return 0;
}