#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num1=0;
    for(int i = 0; i < 7; i++) {
        int aux;cin>>aux;
        if(aux == 1) num1++;
    }

    bool seg;cin>>seg;

    if(seg == num1%2) cout << "N?\n";
    else cout << "S\n";

    return 0;
}