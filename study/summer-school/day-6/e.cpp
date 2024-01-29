#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

int n;
int a[60];

void solve(int t) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    int ans = abs(a[0]-a[n-1]), i = 1, j = n-2, l = 0, r = n-1;
    while (i <= j) {
        if (
            abs(a[j]-a[r]) >= abs(a[j]-a[l]) && 
            abs(a[j]-a[r]) >= abs(a[i]-a[l]) &&
            abs(a[j]-a[r]) >= abs(a[i]-a[r])
        ) {
            ans += abs(a[j]-a[r]);
            r = j;
            j--;
        } else if (
            abs(a[j]-a[l]) >= abs(a[j]-a[r]) && 
            abs(a[j]-a[l]) >= abs(a[i]-a[l]) &&
            abs(a[j]-a[l]) >= abs(a[i]-a[r])
        ) {
            ans += abs(a[j]-a[l]);
            l = j;
            j--;
        } else if (
            abs(a[i]-a[r]) >= abs(a[i]-a[l]) && 
            abs(a[i]-a[r]) >= abs(a[j]-a[l]) &&
            abs(a[i]-a[r]) >= abs(a[j]-a[r])
        ) {
            ans += abs(a[i]-a[r]);
            r = i;
            i++;
        } else if (
            abs(a[i]-a[l]) >= abs(a[i]-a[r]) && 
            abs(a[i]-a[l]) >= abs(a[j]-a[l]) &&
            abs(a[i]-a[l]) >= abs(a[j]-a[r])
        ) {
            ans += abs(a[i]-a[l]);
            l = i;
            i++;
        }
    }
    cout << "Case " << t << ": " << ans << '\n';
}

int main() {
    
    int t=1;
    cin>>t;
    for(int i = 1;i <= t; i++){
        solve(i);
    }


    return 0;
}
