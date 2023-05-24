#include <iostream>
#include <vector>

using namespace std;

int MAX = 1e5 + 1;

typedef long long int ll;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int aux;
    vector<int> count;
    count.assign(MAX, 0);

    for(int i = 0; i < n; i++) {
        cin >> aux;
        count[aux]++;
    }

    ll acc = 0;

    acc += (ll)count[1] * (ll)(count[1] - 1) / 2;

    for(int i = 2; i < MAX; i++) {
        if(count[i] == 0) continue;

        acc += (ll)count[1] * (ll)count[i];
        acc += (ll)count[i] * (ll)(count[i] - 1) / 2;

        for(int j = 2; j * j <= i; j++) {
            if(i % j) continue;

            acc += (ll)count[i] * (ll)count[j];

            if(j * j != i) {
                acc += (ll)count[i/j] * (ll)count[i];
            }
        }
    }

    cout << acc << endl;

    return 0;
}