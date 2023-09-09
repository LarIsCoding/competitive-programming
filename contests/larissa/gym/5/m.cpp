#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

ll v[5005];
ll memo[5005][3];

ll mod=998244353;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    v[0]=0;
    for(int i =1;i<=n;i++) {
        cin>>v[i];
    }

    memo[0][0]=0;
    memo[0][1]=0;
    memo[0][2]=0;
    memo[1][0]=1;
    memo[1][1]=0;
    memo[1][2]=0;

    for(int i =2;i<=n;i++) {
        memo[i][0]=((memo[i-1][0]+memo[i-1][1])%mod+memo[i-1][2])%mod;
        memo[i][1]=0;
        int j=i-1;
        for(j;v[j]>v[i];j--) {
            cout << i << ' ' << j << endl;
            memo[i][1]+=(memo[j][0]-memo[j][2])%mod;
        }
        memo[i][2] = ((memo[j][0]+memo[j][1])%mod+memo[j][2])%mod;
        //cout << v[i] << endl;
        //cout << memo[i][0] << ' ' << memo[i][1]<<' '<<memo[i][2]<<endl;
    }

    cout << ((memo[n][0]+memo[n][1])%mod+memo[n][2])%mod<<endl;

    //for(int i=1;i<=5000;i++)
        //cout << i << ' ';
 
    return 0;
}