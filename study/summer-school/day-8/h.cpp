#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
typedef long long ll;

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

typedef complex<double> C;
typedef vector<double> vd;
typedef vector<ll> vl;

void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double> > R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		for(int i=k;i<2*k;i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vl rev(n);
	for(int i=0;i<n;i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	for(int i=0;i<n;i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) for(int j=0;j<k;j++) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}

// Lembrar de troca pra vl caso queira fazer ll e transformar o res para round(x) de ll
vl conv(const vl& a, const vl& b) {
	if (a.empty() || b.empty()) return vl();
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
    for(int i=0;i<sz(b);i++) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	for(int i=0;i<n;i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	for(int i=0;i<sz(res);i++) res[i] = imag(out[i]) / (4 * n);
    vl resl;
    for(double i:res) resl.push_back(round(i));
	return resl;
}

vl binpow(vl a, long long b) {
    vl res;res.push_back(1);
    while (b > 0) {
        if (b & 1)
            res = conv(res,a);
        a = conv(a, a);
        b >>= 1;
    }
    return res;
}

void solve() {
    int n,k;cin>>n>>k;
    vector<int> in(n);
    int maxval=0;
    for(int i=0;i<n;i++) {
        cin>>in[i];
        maxval=max(maxval,in[i]);
    }

    vl v(maxval+1,0);
    for(int i=0;i<n;i++) {
        v[in[i]]=1;
    }

    vl ans=binpow(v,k);

    for(int i=0;i<ans.size();i++) {
        if(ans[i]!=0) cout<<i<<' ';
    }
    cout<<endl;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    //cin >> t;

    for(int i=0;i<t;i++) {
        solve();
    }

    return 0;
}