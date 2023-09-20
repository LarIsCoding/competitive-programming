#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef pair<long double,long double> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

vector<pair<int,ii> > v;

long double epsilon=1e-6;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        long double x,y;int b;
        cin>>x>>y>>b;
        v.push_back(mp(b,mp(x,y)));
    }
    sort(v.rbegin(),v.rend());

    long double l1=0;
    long double r1=acos(-1);

    long double l2=acos(-1);
    long double r2=2*acos(-1);

    long double h=acos(-1);

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(v[j].first==v[i].first) continue;
            double x1=v[i].s.f;
            double y1=v[i].s.s;
            double x2=v[j].s.f;
            double y2=v[j].s.s;

            long double a;
            if(x2==x1) {
                a=h/(long double)2;
            } else {
                long double m=abs(y2-y1)/abs(x2-x1);
                a=atan(m);
            }

            if(y2>=y1&&x2<x1) a=h-a;
            if(y2<y1&&x2<=x1) a=h+a;
            if(y2<y1&&x2>x1) a=2*h-a;

            if((a+epsilon)<h || (a+epsilon)>2*h) {
                l1=max(l1,a);
                r2=min(r2,a+h);
            } else {
                r1=min(r1,a+h-2*h);
                l2=max(l2,a);
            }
        }
    }

    if((l1-epsilon)>r1&&(l2-epsilon)>r2) cout<<"N\n";
    else cout<<"Y\n";

    return 0;
}