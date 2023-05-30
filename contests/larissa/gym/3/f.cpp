#include <iostream>
#include <map>

using namespace std;

typedef long long int ll;

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<ll, ll> numbers;

    ll better = 0;
    for(int i = 0; i < n; i++) {
        ll aux;
        cin >> aux;
        if(numbers.find(aux) == numbers.end()) numbers[aux] = 0;
        numbers[aux]++;
        better = max(better, aux);
    }

    if(numbers.find(1) != numbers.end()) better = max(better, numbers[1]);

    for(ll i = 2; i <= 1e5; i++) {
        ll mul = i;
        ll acc = 0;
        while(mul <= 1e9) {
            if(numbers.find(mul) != numbers.end()) acc += mul * numbers[mul];
            mul *= i;
        }
        better = max(better, acc);
    }

    cout << better << endl;

    return 0;
}