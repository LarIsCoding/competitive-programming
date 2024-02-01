#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
#define inf (int)1e9
#define linf (ll)1e17
typedef pair<int,int> ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

string n, m;

const ll p = 37; // Colocar 53 se tiver minusculo e maiusculo
const ll MOD = 1e9+9;
ll powP[(int)1e6+2], invP[(int)1e6+2];

ll inv_mod(ll a,ll b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}
void init(){
    powP[0] = 1; invP[0] = inv_mod(1,MOD);
    for(int i=1;i<=(int)1e6+1;i++){ 
        powP[i] = (p*powP[i-1])%MOD;
        invP[i] = inv_mod(powP[i],MOD);
    }
}
vector<ll> makeHash(string const& c){ // Constroi o vetor dos Hash
    vector<ll> hashValue(sz(c)+1,0);
    
    for(int i=1;i<=sz(c);i++) hashValue[i] = (hashValue[i-1]+powP[i-1]*(c[i-1]-'a'+1))%MOD;

    return hashValue;
}

ll getHash(vector<ll>& hashValue,int l,int r){ // Te retorna o valor de um Hash
    return (((hashValue[r]-hashValue[l-1]+MOD)%MOD)*invP[l-1])%MOD;
}

int main(){_
    int t; cin>>t; init();

    while(t--){
        cin>>n>>m; int ans = 0;
        ll hashN = makeHash(n).back();
        vector<ll> hashM = {0};

        for(int i=0;i<sz(m);i++){
            int last = sz(hashM);
            hashM.pb((hashM[sz(hashM)-1]+powP[last-1]*(m[i]-'a'+1))%MOD);

            while(sz(hashM)>sz(n) && hashN == getHash(hashM,sz(hashM)-sz(n),sz(hashM)-1)){
                ans++; for(int j=0;j<sz(n);j++) hashM.pop_back();                
            }
        }

        cout<<ans<<'\n';
    }

    return 0;
}