#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {

    while (!cin.eof()) {
        int n, operation, num;
        int isQueue, isStack, isPQ;
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;

        cin >> n;
        isQueue = 1;
        isStack = 1;
        isPQ = 1;

        for (int i = 0; i < n; i++) {
            cin >> operation >> num; 
            
            if(operation == 1) {
                q.push(num);
                s.push(num);
                pq.push(num);
            } else {
                if (q.front() != num) {
                    isQueue = 0;
                }
                q.pop();

                if (s.top() != num) {
                    isStack = 0;
                }
                s.pop();

                if (pq.top() != num) {
                    isPQ = 0;
                }
                pq.pop();
            }
        }

        int total = isQueue + isStack + isPQ;
        if (total > 1) {
            cout << "not sure" << endl;
        } else if (total == 0) {
            cout << "impossible" << endl;
        } else if (isQueue == 1) {
            cout << "queue" << endl;
        } else if (isStack == 1) {
            cout << "stack" << endl;
        } else if (isPQ == 1) {
            cout << "priority queue" << endl;
        }
    }

    return 0;
}