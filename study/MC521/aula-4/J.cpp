#include <iostream>
#include <math.h>

using namespace std;

typedef long long int ll;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, a_, b_;
    cin >> n >> a_ >> b_;

    bool trocou = false;
    ll a;
    ll b;

    if(a_ <= b_) {
        a = a_;
        b = b_;
    } else {
        trocou = true;
        a = b_;
        b = a_;
    }

    ll target = n * 6;
    ll bestA, bestB, bestTotal = ((ll)1e9 * (ll)1e9 + (ll)10);

    ll newA, newB, total;
    for(ll x = 0; x < 6e5; x++) {
        newA = a + x;
        newB = max(b, (ll)ceil((double)target / (double)newA));
        total = newA * newB;
        if(total < bestTotal) {
            bestTotal = total;
            bestA = newA;
            bestB = newB;
        }
    }

    cout << bestTotal << endl;

    if(!trocou) {
        cout << bestA << ' ' << bestB << endl;
    } else {
        cout << bestB << ' ' << bestA << endl;
    }

    return 0;
}