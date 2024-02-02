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

template<int M> vl convMod(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return vl();
	vl res(sz(a) + sz(b) - 1);
	int B=32-__builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(M));
	vector<C> L(n), R(n), outs(n), outl(n);
	for(int i=0;i<sz(a);i++) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
	for(int i=0;i<sz(b);i++) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	for(int i=0;i<n;i++) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / complex<double>(0,1);
	}
	fft(outl), fft(outs);
	for(int i=0;i<sz(res);i++) {
		ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
		ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
		res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
	}
	return res;
}

vl binpow(vl a, long long b) {
    vl res;res.push_back(1);
    while (b > 0) {
        if (b & 1)
            res = convMod<(int)1e9+7>(res,a);
        a = convMod<(int)1e9+7>(a, a);
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