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

struct medida {
    int id;
    int val;
    bool type;
};

vector<medida> v;

bool cmp(medida m1, medida m2) {
    if(m1.val!=m2.val) return m1.val<m2.val;
    if(!m1.type && m2.type) return true;
    if(m1.type && !m2.type) return false;
    return m1.id<m2.id;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        int l,r;cin>>l>>r;
        v.push_back({i+1,l,false});
        v.push_back({i+1,r,true});
    }

    sort(v.begin(),v.end(),cmp);

    int best=0;
    int acc=0;

    for(auto it:v) {
        if(!it.type) {
            acc++;
        }
        else {
            acc--;
        }
        if(acc>best) {
            best=acc;
        }
    }

    set<int> ativo;
    cout<<best<<endl;
    for(auto it:v) {
        if(!it.type) {
            acc++;
            ativo.insert(it.id);
        }
        else {
            acc--;
            ativo.erase(it.id);
        }
        if(acc==best) {
            bool space=false;
            for(int it:ativo) {
                if(space)cout<< ' ';
                space=true;
                cout<<it;
            }
            cout<<endl;
            break;
        }
    }

    return 0;
}