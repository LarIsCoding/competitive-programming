#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long double x, H, L;
    cin >> H >> L;
    x = (H/2 + (L/H)*L/2);
    std::cout << std::fixed << std::setprecision(13);
    cout << x - H << endl;
    return 0;
}
