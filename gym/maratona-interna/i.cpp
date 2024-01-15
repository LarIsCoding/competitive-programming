#include <iostream>
#include <vector>
#include <set>

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

class HashedString {
  private:
	// change M and B if you want
	static const long long M = 1e9 + 9;
	static const long long B = 9973;

	// pow[i] contains B^i % M
	static vector<long long> pow;

	// p_hash[i] is the hash of the first i characters of the given string
	vector<long long> p_hash;

  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
        pow.push_back(1);
		while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }

		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
	}

    // end deve ser a ultima posição
	long long getHash(int start, int end) {
		long long raw_val =
		    (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}
};
vector<long long> HashedString::pow;

int n1,n2;

int bb(int l, int r, HashedString &s1, HashedString &s2) {
    // cout<<l<<' '<<r<<endl;
    if(l==r && l==n1+1) return -1;
    if(l==r) return l;
    int m=(l+r)/2;
    // cout<<m<<endl;

    set<ll> hash;

    for(int i=0;i<n2-m+1;i++) {
        hash.insert(s2.getHash(i,i+m-1));
    }

    for(int i=0;i<n1-m+1;i++) {
        // if(m==3) cout<< i<<endl;
        int h=s1.getHash(i,i+m-1);
        if(hash.find(h)==hash.end()) {
            return bb(l, m, s1, s2);
        }
    }
    return bb(m+1, r, s1, s2);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1,s2;
    cin>>s1>>s2;

    n1=s1.size();
    n2=s2.size();

    HashedString hs1(s1);
    HashedString hs2(s2);

    cout<< bb(1,n1+1,hs1,hs2)<<endl;

    return 0;
}