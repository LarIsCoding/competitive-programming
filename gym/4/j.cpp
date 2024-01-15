#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int randomIndexes[(int)1e4 + 5];

ll binarySearch(int i, ll l, ll r) {
    if(l == r) return l;

    ll m = (l + r + 1) / 2;

    cout << "? " << i << " " << m << endl;
    string answer;
    cin >> answer;

    if(answer[0] == 's') return binarySearch(i, l, m - 1);
    return binarySearch(i, m, r);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w;
    ll h;
    cin >> w >> h;

    for(int i = 1; i <= w; i++) {
        randomIndexes[i] = i;
    }

    random_shuffle(randomIndexes + 1, randomIndexes + w + 1);

    ll higher = 0;
    int index = 1;
    for(int i = 1; i <= w; i++) {
        cout << "? " << randomIndexes[i] << " " << higher + 1 << endl;

        string answer;
        cin >> answer;

        if(answer[0] == 's') continue;

        higher = binarySearch(randomIndexes[i], higher + 1, h);
        index = randomIndexes[i];
        if(higher == h) break;
    }

    cout << "! " << index << " " << higher << endl;

    return 0;
}