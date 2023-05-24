#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<4> foo(9); // 1001
    bitset<4> bar(string("0011"));

    cout << (foo & bar) << endl;  // 0001 (AND)
    cout << (foo | bar) << endl;  // 1011 (OR)
    cout << (foo ^ bar) << endl;  // 1010 (XOR)
    cout << (~bar) << endl;       // 1100 (NOT)
    cout << (bar << 1) << endl;   // 0110 (SHL)
    cout << (bar >> 1) << endl;   // 0001 (SHR)
    cout << (foo == bar) << endl; // false (0110 == 0011)
    cout << (foo != bar) << endl; // true (0110 != 0011)

    foo.reset(0); // seta bit na pos 0 para false -> 1000
    foo.reset(); // seta todos os bits para falses -> 0000

    foo.set(1); // seta bit na pos 0 para true -> 0010
    foo.set(); // seta todos os bits para true -> 1111

    cout << foo[1] << endl; // 1
    cout << foo.test(1) << endl; // true

    return 0;
}