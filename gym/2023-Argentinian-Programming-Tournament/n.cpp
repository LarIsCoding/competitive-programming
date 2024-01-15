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

    int n;
    cin >> n;

    int f[5];
    f[0]=0;
    f[1]=0;
    f[2]=0;
    f[3]=0;
    f[4]=0;

    for(int i=0;i<n;i++) {
        int aux;cin>>aux;
        f[aux%5]++;
    }

    int acc=0;
    acc+=f[0];

    int n14=min(f[1],f[4]);
    acc+=n14;
    f[1]=f[1]-n14;
    f[4]=f[4]-n14;

    int n23=min(f[2],f[3]);
    acc+=n23;
    f[2]=f[2]-n23;
    f[3]=f[3]-n23;

    if(f[1]>0) {
        if(f[2]>0) {
            int n2=f[2]/2;
            int n12=min(f[1],n2);
            acc+=n12;
            f[1]-=n12;
            f[2]-=n12*2;

            int n1=f[1]/3;
            n12=min(f[2],n1);
            acc+=n12;
            f[1]-=n12*3;
            f[2]-=n12;
        }
        if(f[3]>0) {
            int n1=f[1]/2;
            int n13=min(f[3],n1);
            acc+=n13;
            f[1]-=n13*2;
            f[3]-=n13;

            int n3=f[3]/3;
            n13=min(f[1],n3);
            acc+=n13;
            f[1]-=n13;
            f[3]-=n13*3;
        }
        acc+=f[1]/5;
    }

    if(f[2]>0) {
        if(f[4]>0) {
            int n4=f[4]/2;
            int n24=min(f[2],n4);
            acc+=n24;
            f[2]-=n24;
            f[4]-=n24*2;

            int n2=f[2]/3;
            n24=min(f[4],n2);
            acc+=n24;
            f[2]-=n24*3;
            f[4]-=n24;
        }
        acc+=f[2]/5;
    }

    if(f[3]>0) {
        if(f[4]>0) {
            int n3=f[3]/2;
            int n34=min(f[4],n3);
            acc+=n34;
            f[3]-=n34*2;
            f[4]-=n34;
            
            int n4=f[4]/3;
            n34=min(f[3],n4);
            acc+=n34;
            f[2]-=n34;
            f[4]-=n34*3;
        }
        acc+=f[3]/5;
    }

    if(f[4]>0) {
        acc+=f[4]/5;
    }
    cout<<acc<<endl;

    return 0;
}