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
        int l,r;cin>>l>>r;

        if(r<4) {
            cout<<-1<<endl;
        }
        else if(l!=r || l%2==0) {
            int num;
            if(r%2==0) num=r;
            else num=r-1;
            cout<<num/2<<' '<<num/2<<endl;
        } else {
            int x=sqrt(l);
            bool found=false;

            for(int i=2;i<=x;i++) {
                if(l%i==0) {
                    int a=i;
                    int b=l/a;
                    cout<<a<<' '<<a*(b-1)<<endl;
                    found=true;
                    break;
                }
            }
            if(found) continue;

            cout<<-1<<endl;
        }
    }

    return 0;
}