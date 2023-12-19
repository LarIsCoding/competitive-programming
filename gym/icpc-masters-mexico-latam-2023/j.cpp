#include <iostream>
#include <vector>
#include <cstring>

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

#define isOn(S, j) (S & (1 << j))        // checa se bit j é true

vi dislike[21];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k,f;
    cin>>n>>k>>f;

    for(int i=0;i<f;i++) {
        int t;cin>>t;
        while(t--) {
            int aux;cin>>aux;
            dislike[i].push_back(aux);
        }
    }

    int best=0;
    for(int i=0;i<(1<<f);i++) {
        bool remove[n+1];
        memset(remove,false,sizeof remove);
        int total=0;
        for(int j=0;j<f;j++) {
            if(isOn(i,j)) {
                total++;
                for(int it:dislike[j]) {
                    remove[it]=true;
                }
            }
        }
        int rem=0;
        for(int j=0;j<=n;j++) if(remove[j]) rem++;
        if(rem<=(n-k)) best=max(best,total);
    }
    
    cout<<best<<endl;

    return 0;
}