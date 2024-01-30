#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

string v[(int)5e4];

int cmp(string s1, string s2) {
    return ((s1+s2)<(s2+s1));
}

void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    sort(v,v+n,cmp);
    for(int i=0;i<n;i++) {
        cout<<v[i];
    }
    cout<<endl;
}

int main() {
    
    int t=1;
    //cin>>t;
    for(int i = 0;i < t; i++){
        solve();
    }


    return 0;
}
