#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;cin>>n;

    cout<<n;

    while(n != 1) {
        if(!(n%2)) {
            n/=2;
        } else {
            n*=3;n++;
        }
        cout<<' '<<n;
    }

    cout<<endl;

    return 0;
}