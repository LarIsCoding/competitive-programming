#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define toggleBit(S, j) (S ^= (1 << j))

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int freq[256];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;cin>>s;

    memset(freq, 0, sizeof(freq));

    ll total = 0;
    int mask = 0;
    freq[mask]++;
    
    for(int i = 0; i < n; i++) {
        int index = s[i] - 'a';
        toggleBit(mask, index);

        for(int j = 0; j < 8; j++) {
            int target = mask ^ (1<<j);
            total += (ll)freq[target];
        }
        int target = mask | 0;
        total += (ll)freq[target];

        freq[mask]++;
    }

    cout << total << endl;

    return 0;
}