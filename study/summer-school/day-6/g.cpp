#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 


void solve(){
    int n;cin>>n;
    if(n%2) cout<<"Either\n";
    else if(n%4==0) cout<<"Even\n";
    else cout<<"Odd\n";
}

int main() {
    
    int t=1;
    //cin>>t;
    for(int i = 0;i < t; i++){
        solve();
    }


    return 0;
}