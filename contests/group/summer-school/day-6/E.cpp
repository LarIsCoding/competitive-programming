#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long num[n];
    long long aux;

    for(long long i = 0; i < n; i++) {
        cin >> aux;
        num[i] = aux;
    }
    sort(num, num + n);

    long long numZero = 0;
    while(num[numZero] == 0 && numZero < n) numZero++;

    long long distSquare[n];
    long long s1 = 0;
    long long s2 = 1;
    long long n2 = 2;

    for(long long i = 0; i < n; i++) {
        while(num[i] > s2) {
            s1 = s2;
            s2 = n2 * n2;
            n2++;
        }
        distSquare[i] = min(abs(num[i] - s1), abs(s2 - num[i]));
    }

    sort(distSquare, distSquare + n);

    long long numDistZero = 0;
    while(distSquare[numDistZero] == 0 && numDistZero < n) numDistZero++;

    long long metade = n / 2;
    long long sum = 0;

    if (numDistZero > metade) {
        sum = numDistZero - metade + min(numZero, metade);
    } else {
        for(long long i = numDistZero; i < metade; i++) {
            sum += distSquare[i];
        }
    }

    cout << sum << endl;

    return 0;
}