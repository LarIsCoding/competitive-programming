#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;cin>>s;

    int maxL=1;
    int acc=0;
    char last='x';

    for(auto c:s) {
        if(c==last) {
            acc++;
            maxL=max(acc, maxL);
        } else {
            acc=1;
            last=c;
        }
    }

    cout<<maxL<<endl;

    return 0;
}