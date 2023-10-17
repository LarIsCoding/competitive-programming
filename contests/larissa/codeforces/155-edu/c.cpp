#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)998244353;
const ll linf = (ll)1e17;

int memo[(int)2e5+5];

ll fat(ll n) {
    if(n==1||n==0) return 1;
    if(memo[n]!=-1) return memo[n];
    return memo[n]=(n*fat(n-1))%mod;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string s;cin>>s;

        ll sum=0;
        ll acc=1;
        ll numGroups=0;
        ll comb=1;

        for(int i=1;i<s.size();i++) {
            if(s[i]==s[i-1]) {
                acc++;
            } else {
                if(acc>1) {
                    numGroups++;
                    sum+=acc-1;
                    comb=(comb*acc)%mod;
                    acc=1;
                }
            }
        }
        if(acc>1) {
            numGroups++;
            sum+=acc-1;
            comb=(comb*acc)%mod;
            acc=1;
        }

        memset(memo,-1, sizeof memo);
        cout<<sum<<' '<<(comb*fat(sum))%mod<<endl;
    }

    return 0;
}