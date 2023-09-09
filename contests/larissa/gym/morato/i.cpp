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

set<ii> spaces;
int pos[(int)2e5+5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int id=1;

    for(int i=0;i<n;i++) {
        int aux;cin>>aux;
        pos[i+1]=aux;
        if(id < aux) spaces.insert(mp(id,aux-1));
        id=aux+1;
    }

    int q;cin>>q;
    while(q--){
        int i;cin>>i;
        auto x = upper_bound(spaces.begin(),spaces.end(),mp(pos[i],pos[i]));
        if(x!=spaces.begin()) {
            auto aux=x;aux--;
            if(aux->second==pos[i]-1) {
                spaces.insert(mp(aux->first,pos[i]));
                spaces.erase(aux);
            } else {
                spaces.insert(mp(pos[i],pos[i]));
            }
        } else {
            spaces.insert(mp(pos[i],pos[i]));
        }
        if(x == spaces.end()) {
            cout<<id<<endl;
            pos[i]=id;
            id++;
        } else {
            pos[i]=x->first;
            cout<<x->first<<endl;
            if(x->first < x->second) spaces.insert(mp(x->first+1,x->second));
            spaces.erase(x);
        }
    }

    return 0;
}