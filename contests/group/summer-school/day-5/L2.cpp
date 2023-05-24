#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n, t, d, soma = 0;
    cin >> n;
    for (long long i = 0; i < n; i++){
        cin >> d >> t;
        if (d <= soma) soma += t;
        else soma = d + t;
    }
    cout << soma;
    return 0;
}
