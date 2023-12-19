#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    bool v[n+1];
    memset(v,false,n+1);

    for(int i=0;i<n-1;i++) {
        int aux;cin>>aux;
        v[aux]=true;
    }

    for(int i=1;i<=n;i++) {
        if(!v[i]) {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}