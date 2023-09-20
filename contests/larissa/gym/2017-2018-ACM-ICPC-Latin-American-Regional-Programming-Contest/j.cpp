#include <iostream>
#include <vector>

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

#define FOR(i,b) for(int i=0;i<(b);i++)

template<class T>
struct Sieve{
    vi primes;

    Sieve(int M = (int)1e6+6){
        vector<char> is_prime(M,true);
        is_prime[0] = is_prime[1]=false;
        for(int i=2;i*i<M;i++) {
            if(is_prime[i]) {
                for(int j=i*i;j<M;j+=i)
                    is_prime[j]=false;
            }
        }

        FOR(i,M) {
            if(is_prime[i])
                primes.push_back(i);
        }
    }

    vi decomp(T n) {
        vi fats;
        for(int d:primes) {
            if(d*1LL*d>n) {
                break;
            }
            while(n%d==0) {
                fats.push_back(d);
                n/=d;
            }
        }
        if(n>1) {
            fats.push_back(n);
        }
        return fats;
    }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n=s.size();

    bool failed=false;
    for(int i=0;i<n;i++) {
        if(s[i]=='P') {
            failed=true;
            break;
        }
    }

    if(!failed) {
        cout<<n-1<<endl;
        return 0;
    }

    Sieve<int> sieve((int)1e5 + 5);
    auto fatores = sieve.decomp(n);
    fatores.resize(std::unique(fatores.begin(), fatores.end()) - fatores.begin());

    int r=0;
    for(auto it:fatores) {
        // cout<<it<<endl;
        for(int i=0;i<it;i++) {
            bool failed=false;
            for(int j=i;j<n;j+=it) {
                // cout<<j<<' '<<s[j]<<endl;
                if(s[j]=='P') {
                    failed=true;
                    break;
                }
            }
            // cout<<i<<' '<<failed<<endl;
            if(!failed) {
                r+=(n/it - 1);
                break;
            }
        }
        // cout<<r<<endl;
    }
    cout<<r<<endl;

    return 0;
}