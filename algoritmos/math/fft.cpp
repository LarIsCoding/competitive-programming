#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
typedef complex<double> C;
typedef vector<double> vd;
typedef vector<ll> vl;

void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		for(int i=k;i<2*k;i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
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
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
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
	return res;
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

// Hoffman - Multiplicação de multiplos  polinomios

struct cmp{
 bool operator()(const vl& a,const vl& b) const {
  return sz(a) < sz(b);
 }
};

multiset<vl, cmp > S;
const int M =1e9+7;

vl multiplePoly(){
    while(S.size() > 1){
        auto it = S.begin();
        auto it2 = it;
        it++;
        S.insert(convMod<M>(*it,*it2));
        S.erase(it);S.erase(it2);
    }
    vl res = *S.begin();

    return res;
}

// O(N^2) -> Bom para multiplicação de polinomios de tamanho 2
vl trivialMul(const vl &a, const vl &b){
    vl res(sz(a)+sz(b)-1,0);
    
    for(int i=0;i<sz(a);i++){
        for(int j=0;j<sz(b);j++){
            res[i+j] += a[i]*b[j];
        }
    }

    return res;
}