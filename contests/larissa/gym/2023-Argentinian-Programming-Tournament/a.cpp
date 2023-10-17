#include <bits/stdc++.h>

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

int e[(int)1e5+5];

set<ii> s;

vector<ii> ans;

bool cmp(ii a, ii b) {
    return a.second<b.second;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++) {
        int aux;cin>>aux;
        s.insert(mp(aux,i));
    }

    for(int i=0;i<m;i++) {
        cin>>e[i];
    }

    for(int i=0;i<m;i++) {
        auto it=s.end();it--;
        while(it!=s.end(),it->first>=e[i]) {
            ii aux=*it;
            it--;
            s.erase(aux);
            s.insert(mp(aux.first%e[i],aux.second));
        }
    }

    for(auto it:s) {
        ans.push_back(it);
    }

    sort(ans.begin(),ans.end(),cmp);

    bool space=false;
    for(auto it:ans) {
        if(space) cout<<' ';
        space=true;
        cout<<it.first;
    }
    cout<<endl;

    return 0;
}