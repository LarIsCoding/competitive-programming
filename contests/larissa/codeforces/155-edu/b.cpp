#include <bits/stdc++.h>

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

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        ll n;cin>>n;

        ll minA=inf, sumA=0;
        for(int i=0;i<n;i++) {
            ll aux;cin>>aux;
            minA=min(minA,aux);
            sumA+=aux;
        }

        ll minB=inf, sumB=0;
        for(int i=0;i<n;i++) {
            ll aux;cin>>aux;
            minB=min(minB,aux);
            sumB+=aux;
        }

        cout<<min(minA*n+sumB,minB*n+sumA)<<endl;
    }

    return 0;
}