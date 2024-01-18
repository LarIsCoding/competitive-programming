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

const int MAXN = 1e5;
const int MAXNSQRT = 400;
int a[MAXN];
ll prefixSum[MAXNSQRT][MAXN], sumAcc[MAXNSQRT][MAXN];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n,q;cin>>n>>q;

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        for(int i=0;i<MAXNSQRT;i++) {
            for(int j=0;j<=i && j<n;j++) {
                prefixSum[i][j]=a[j];
                sumAcc[i][j]=a[j];
            }
            for(int j=i+1;j<n;j++) {
                prefixSum[i][j]=prefixSum[i][j-i-1] + (ll)a[j];
                sumAcc[i][j]=sumAcc[i][j-i-1]+(ll)ceil((double)(j+1)/(double)(i+1))*(ll)a[j];
            }
        }

        bool space=false;
        while(q--) {
            int s,d,k;cin>>s>>d>>k;s--;
            if(d<MAXNSQRT) {
                int end=s+(k-1)*d;
                ll t=sumAcc[d-1][end];
                ll sub=0;
                if((s-d)>=0) sub=sumAcc[d-1][s-d]+(prefixSum[d-1][end]-prefixSum[d-1][s-d])*(s/d);
                ll r=t-sub;
                if(space)cout<<' ';
                space=true;
                cout<<r;
            } else {
                ll r=0;
                for(int i=0;i<k && (s+i*d)<n ;i++) {
                    r+=(ll)a[s+i*d]*(ll)(i+1);
                }
                if(space)cout<<' ';
                space=true;
                cout<<r;
            }
        }
        cout<<endl;
    }

    return 0;
}