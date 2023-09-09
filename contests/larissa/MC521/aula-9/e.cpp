#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
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

    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vi count;
        count.assign(55, 0);

        for(int i=0;i<n;i++){
            int l,r;
            cin>>l>>r;
            if(l>k || r<k) continue;
            for(int j=l;j<=r;j++){
                count[j]++;
            }
        }

        bool failed = false;
        for(int i=0; i<=50;i++) {
            if(i == k) continue;
            if(count[i] >= count[k]) {
                failed = true;
                break;
            }
        }

        if(failed) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}