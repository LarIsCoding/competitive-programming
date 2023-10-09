#include <iostream>
 
using namespace std;
 
typedef pair<int,int> ii;
typedef long long int ll;
 
#define mp(i, j) make_pair(i, j)
#define f first
#define s second
 
const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;
 
struct Matrix {
    ll a11,a12,a21,a22;
};
 
Matrix mul(Matrix m1, Matrix m2) {
    Matrix r;
    r.a11=((m1.a11*m2.a11)%mod+(m1.a12*m2.a21)%mod + mod)%mod;
    r.a12=((m1.a11*m2.a12)%mod+(m1.a12*m2.a22)%mod + mod)%mod;
    r.a21=((m1.a21*m2.a11)%mod+(m1.a22*m2.a21)%mod + mod)%mod;
    r.a22=((m1.a21*m2.a12)%mod+(m1.a22*m2.a22)%mod + mod)%mod;
    return r;
}
 
Matrix binpow(Matrix a, ll b) {
    Matrix res = {1,0,0,1};
    while (b > 0) {
        if (b & 1)
            res = mul(a,res);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}
 
int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n,d,k,s;
    cin>>n>>d>>k>>s;
 
    ll m0=1+min(2*d+1,n);
    ll m1=-min(2*d+1,n);
    ll m2=1;
    ll m3=0;
    Matrix m={m0,m1,m2,m3};
 
    Matrix r = binpow(m,k-1);
 
    cout<<r.a11<<endl;
 
    return 0;
}