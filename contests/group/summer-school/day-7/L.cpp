#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n;

    int v[n];
    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> t;
        v[i] = t;
        sum += t;
    }

    int media = sum / n;
    if(sum % n != 0) media++;

    for(int i = 0; i < n - 1; i++) {
        if (v[i] > media) {
            int sub = v[i] - media + ((v[i] - media) % 2);
            v[i + 1] += sub;
            v[i] -= sub / 2;
        }
    }

    int maximum = 0;
    for(int i = 0; i < n; i++) {
        maximum = max(maximum, v[i]);
    }

    cout << maximum << endl;

    return 0;
}