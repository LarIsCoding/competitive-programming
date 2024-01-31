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
#define EPS 1e-9

int memo[101][(int)1e5];
int a[101];

int getNum(string s) {
    return (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
}

int dp(int i, int v) {
    string s=to_string(v);
    while(s.size()<4) s="0"+s;
    sort(s.begin(),s.end());
    int n=getNum(s);
    cout<<s<<' '<<n<<endl;
    if(memo[i][n]!=-1) return memo[i][n];

    int best=dp(i-1,n);

    do {
        int m=getNum(s);
        if(m>=a[i]) best=max(best,dp(i-1,m-a[i])+1);
    } while((next_permutation(s.begin(),s.end())));

    return memo[i][n]=best;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,x;cin>>n>>x;

    memset(memo,-1,sizeof memo);

    for(int i=0;i<n;i++) {
        memo[i][0]=0;
    }
    for(int i=0;i<1e5;i++) {
        memo[0][i]=0;
    }

    cout<<dp(n,x)<<endl;

    return 0;
}
