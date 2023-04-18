#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;

    s.insert(7);
    s.insert(80);

    cout << *s.find(7) << endl;

    for(set<int>::iterator it = s.lower_bound(77); it != s.end(); it++)
        cout << *it << endl;

    int d = distance(s.begin(), s.end());
    s.clear();

    return 0;
}