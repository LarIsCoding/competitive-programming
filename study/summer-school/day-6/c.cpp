#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

int v[(int)3e5+5];

void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    int acc=0;
    vector<pair<int,int> > ans;
    set<int> p;
    int last=0;
    for(int i=0;i<n;i++) {
        if(p.find(v[i])==p.end()) {
            p.insert(v[i]);
            continue;
        }
        acc++;
        ans.push_back({last+1,i+1});
        last=i+1;
        p.clear();
    }

    if(ans.empty()) {
        cout<<-1<<endl;
        return;
    }

    ans[acc-1].second=n;
    cout<<acc<<endl;
    for(int i=0;i<acc;i++) {
        cout<<ans[i].first <<' '<<ans[i].second<<'\n';
    }
}

int main() {
    
    int t=1;
    //cin>>t;
    for(int i = 0;i < t; i++){
        solve();
    }


    return 0;
}