#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c1,b1,p1,c2,b2,p2;
    cin>>c1>>b1>>p1>>c2>>b2>>p2;

    int r=0;
    if(c2>c1) {
        r+=c2-c1;
    }
    if(b2>b1) {
        r+=b2-b1;
    }
    if(p2>p1) {
        r+=p2-p1;
    }
    cout<<r<<endl;

    return 0;
}