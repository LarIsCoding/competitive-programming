#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if (x%2 == 0 && y%2 == 0) cout << x/2 << " " << y/2 << endl;
        else if (x%2 == 0) cout << -1 << " " <<  -1 << endl;
        else if (y%2 == 0) cout << -1 << " " << -1 << endl;
        else if (x > y) cout << (x-y)/2 << " " << y << endl;
        else if (x < y) cout << x << " " << (y-x)/2 << endl;
        else if (x == y) cout << x/2 << " " << x/2 + 1 << endl;
    }
    return 0;
}
