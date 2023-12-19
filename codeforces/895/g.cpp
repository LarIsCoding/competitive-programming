#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int memo[(int)2e5][2];
int a[(int)2e5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;cin>>n;

        int mul=1;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            mul*=a[i];
        }

        int best=0;
        for(int i=0;i<n;i++) {
            sum-=a[i];
            if(memo[i][0]+sum>best) {
                best=memo[i][0]+sum;
                l=memo[i][1]+1;
                r=i+1;
            }
        }

        cout<<l<<' '<<r<<endl;
    }

    return 0;
}