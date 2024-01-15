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

int v[(int)2e5+5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    v[0]=2;
    v[1]=3;
    int num=4;

    for(int i=2;i<=(int)2e5;i++) {
        while((num*3)%(v[i-1]+v[i-2])==0) num++;
        v[i]=num;
        num++;
    }

    while(t--) {
        int n;cin>>n;
        for(int i=0;i<n;i++) {
            if(i>0) cout<<' ';
            cout<<v[i];
        }
        cout<<endl;
    }

    return 0;
}