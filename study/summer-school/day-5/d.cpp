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

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;cin>>n;
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<n;i++) {
            int x;cin>>x;
            pq.push(x);
        }

        int acc;
        while(pq.size()>1) {
            int a,b;
            a=pq.top();pq.pop();
            b=pq.top();pq.pop();
            int r=a+b;
            pq.push(r);
            acc+=r;
        }

        cout<<acc<<endl;
        pq.pop();
        acc=0;
    }

    return 0;
}