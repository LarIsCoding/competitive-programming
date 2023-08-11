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

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        int n;
        cin>>n;

        string s;cin>>s;

        int sum = 0;
        for(int j=0;j<n;j++){
            if(s[j]=='.'){
                sum++;
                j+=2;
            }
        }
        cout<< "Case " << i << ": " << sum<<endl;
    }

    return 0;
}