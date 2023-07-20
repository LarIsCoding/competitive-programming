#include <iostream>
#include <set>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int INF = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

set<int> maxPq;
set<int> minPq;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    ll pos = 0;
    ll total = 0;

    maxPq.insert(0);
    minPq.insert(INF);

    while(q--) {
        char op; cin >> op;
        ll x; cin>>x;

        if(op == '+') {
            if(pos == 0) {
                pos = x;
                total = 0;
            } else if(x > pos) {
                minPq.insert(x);
                if(minPq.size() > maxPq.size() + 1) {
                    maxPq.insert(pos);
                    pos = *minPq.begin();
                    minPq.erase(pos);
                }
                total += abs(x - pos);
            } else {
                maxPq.insert(x);
                if(maxPq.size() > minPq.size() + 1) {
                    minPq.insert(pos);
                    auto aux = maxPq.end();
                    aux--;
                    pos = *aux;
                    maxPq.erase(pos);
                }
                total += abs(x - pos);
            }
        } else {
            if(x == pos) {
                if(minPq.size() < maxPq.size()) {
                    auto aux = maxPq.end();
                    aux--;
                    pos = *aux;
                    maxPq.erase(pos);
                    total -= abs(x - pos);
                } else if(minPq.size() > maxPq.size()) {
                    pos = *minPq.begin();
                    minPq.erase(pos);
                    total -= abs(x - pos);
                } else if(minPq.size() == 1 && maxPq.size() == 1) {
                    pos = 0;
                    total = -1;
                } else {
                    pos = *minPq.begin();
                    minPq.erase(pos);
                }
            } else if(x > pos) {
                minPq.erase(x);
                if(maxPq.size() > minPq.size() + 1) {
                    minPq.insert(pos);
                    auto aux = maxPq.end();
                    aux--;
                    pos = *aux;
                    maxPq.erase(pos);
                }
                total -= abs(x - pos);
            } else {
                maxPq.erase(x);
                if(minPq.size() > maxPq.size() + 1) {
                    maxPq.insert(pos);
                    pos = *minPq.begin();
                    minPq.erase(pos);
                }
                total -= abs(x - pos);
            }
        }
        cout << total << endl;
    }

    return 0;
}