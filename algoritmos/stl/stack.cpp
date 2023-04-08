#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    
    st.push(4);
    st.push(7);
    st.pop();

    cout << st.top() << endl;
    cout << st.empty() << endl;

   return 0;
}