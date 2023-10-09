#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

#define FOR(i, b) for(int i = 0; i < (b); i++)
 
template<typename T>
struct Matrix {
  vector<vector<T> > raw;
  int n, m;
 
  Matrix(int n, int m, T val = 0): n(n), m(m) {
    raw.assign(n, vector<T>(m, val));
  }
 
  vector<T>& operator[](int i){
    return raw[i];
  }
 
  Matrix operator*(Matrix &other) {
    #ifndef ONLINE_JUDGE
    assert(m == other.n);
    #endif
    Matrix ans(n, other.m);
    FOR(i, n)
      FOR(j, other.m)
        FOR(k, m)
          ans[i][j] = ans[i][j] + raw[i][k] * other[k][j];
 
    return ans;
  }
 
  Matrix pow(ll k) {
    #ifndef ONLINE_JUDGE
    assert(n == m);
    #endif
    Matrix ans(n, n);
    Matrix tmp = *this;
 
    FOR(i, n)
      ans[i][i] = 1;
 
    while (k > 0) {
      if (k & 1) ans = ans * tmp;
      tmp = tmp * tmp;
      k >>= 1;
    }
    return ans;
  }
 
  friend void print(Matrix a) {
    FOR(i, a.n)
      FOR(j, a.m)
        cout << a[i][j] << " \n"[j + 1 == a.m];
    cout.flush();
  }
};
 
template <int MOD>
struct MINT{
  int v;
 
  MINT(ll val = 0){
    v = (-MOD <= val && val < MOD) ? val : val % MOD;
    if(v < 0) v += MOD;
  }
 
  MINT operator - () const { return MINT(-v); }
  MINT operator * (const MINT& m2) const { return v * 1LL * m2.v % MOD; }
  MINT operator / (const MINT& m2) const { return (*this) * inv(m2); }
  MINT& operator *= (const MINT& m2){ return (*this) = (*this) * m2; }
  MINT& operator /= (const MINT& m2){ return (*this) = (*this) / m2; }
  MINT& operator += (const MINT& m2){ return (*this) = (*this) + m2; }
  MINT& operator -= (const MINT& m2){ return (*this) = (*this) - m2; }
  bool operator == (const MINT& m2) const { return v == m2.v; }
  bool operator != (const MINT& m2) const { return v != m2.v; }
  bool operator < (const MINT& m2) const { return v < m2.v; }
  friend istream& operator >> (istream &is, MINT &a) { ll t; is >> t; a = MINT(t); return is; }
  friend ostream& operator << (ostream &os, const MINT &a) { return os << a.v; }
  friend MINT inv(const MINT& a) { return pw(a, MOD - 2); } // only if MOD is prime
 
  MINT operator + (const MINT& m2) const{
    int tmp = v + m2.v;
    return tmp >= MOD ? tmp - MOD : tmp;
  }
 
  MINT operator - (const MINT& m2) const{
    int tmp = v - m2.v;
    return tmp < 0 ? tmp + MOD : tmp;
  }
 
  friend MINT pw(MINT a, ll b){
    MINT ret = 1;
    while(b){
      if(b & 1) ret *= a;
      b >>= 1; a *= a;
    }
    return ret;
  }
};
 
using mint = MINT<1000'000'007>;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,d,k,s;
    cin>>n>>d>>k>>s;

    Matrix<mint> mat(2,2);

    mat[0][0] = 1+min(2*d+1,n);
    mat[0][1] = -min(2*d+1,n);
    mat[1][0] = 1;
    mat[1][1] = 0;

    Matrix<mint> ans = mat.pow(k-1);
    cout << ans[0][0] << endl;

    return 0;
}