#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;cin>>t;

    while(t--) {
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

        int a;

        if(x1==x2) {
            a = abs(x3-x1) * abs(y1-y2);
        } else if(x1==x3) {
            a = abs(x2-x1) * abs(y1-y3);
        } else {
            a = abs(x2-x1) * abs(y1-y4);
        }
        cout<<a<<endl;
    }
    return 0;
}