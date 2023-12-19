#include <iostream>

using namespace std;

typedef pair<int, bool> ib;

pair<int, bool> getConsumption(int price) {
    int left = price;
    int consumption = 0;
    bool exato = true;

    int range = 100;
    if(left <= range * 2) {
        if(left % 2) exato = false;
        consumption += left / 2;
        return make_pair(consumption, exato);
    }

    consumption += range;
    left -= range * 2;

    range = 10000 - 100;
    if(left <= range * 3) {
        if(left % 3) exato = false;
        consumption += left / 3;
        return make_pair(consumption, exato);
    }

    consumption += range;
    left -= range * 3;

    range = 1000000 - 10000;
    if(left <= range * 5) {
        if(left % 5) exato = false;
        consumption += left / 5;
        return make_pair(consumption, exato);
    }

    consumption += range;
    left -= range * 5;

    if(left % 7) exato = false;
    consumption += left / 7;
    return make_pair(consumption, exato);
}

int getBilling(int consumption) {
    int left = consumption;
    int total = 0;

    int range = 100;
    if(left < range) {
        total += left * 2;
        return total;
    }

    total += range * 2;
    left -= range;

    range = 10000 - 100;
    if(left < range) {
        total += left * 3;
        return total;
    }

    total += range * 3;
    left -= range;

    range = 1000000 - 10000;
    if(left < range) {
        total += left * 5;
        return total;
    }

    total += range * 5;
    left -= range;

    total += left * 7;
    return total;
}

int busca(int l, int r, int A, int B) {
    int billing = (l + r) / 2;
    int neighbour = B + billing;

    ib myConsumption = getConsumption(billing);
    ib neighbourConsumption = getConsumption(neighbour);
    int totalBilling = getBilling(myConsumption.first + neighbourConsumption.first);

    if(totalBilling == A) {
        if(myConsumption.second && neighbourConsumption.second) return billing;
        return busca(l, billing - 1, A, B);
    }
    if(totalBilling > A) return busca(l, billing - 1, A, B);
    return busca(billing + 1, r, A, B);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A, B;
    cin >> A >> B;

    while(A != 0) {
        cout << busca(0, A, A, B) << endl;
        cin >> A >> B;
    }

    return 0;
}