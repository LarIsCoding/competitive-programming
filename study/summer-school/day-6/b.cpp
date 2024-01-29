#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 


void solve(){
    int n;
    cin >> n;

    ll acc = 0;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        acc += a[i];
    }

    ll ans = 0, val = acc/n, rest = acc%n;
    for (int i = 0; i < n; i++) {
        if (rest > 0 && abs(a[i]-val-1) < abs(a[i]-val)) {
            ans += abs(a[i]-val-1);
            rest--;
        } else {
            ans += abs(a[i]-val);
        }
    }
    ans += rest;
    cout << ans/2 << '\n';
}

int main() {
    
    int t=1;
    //cin>>t;
    for(int i = 0;i < t; i++){
        solve();
    }


    return 0;
}