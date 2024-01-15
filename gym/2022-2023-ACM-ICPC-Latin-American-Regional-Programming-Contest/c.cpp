#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll p,h;
    cin>>n>>p>>h;

    // h=pow((ll)2,(ll)n);
    // cout<<h<<endl;

    ll maxH=pow((ll)2,(ll)n);
    stack<int> st;

    for(int i=0;i<n;i++) {
        if(h<=maxH/(ll)2) {
            st.push(0);
        } else {
            st.push(1);
            h=maxH-h+(ll)1;
        }
        maxH/=(ll)2;
    }

    ll maxW=pow((ll)2,(ll)n);

    for(int i=0;i<n;i++) {
        int op = st.top();
        st.pop();

        if(op==0) {
            if(p<=maxW/(ll)2) cout << 'R';
            else {
                cout<<'L';
                p=p-(maxW/2);
            }
        } else {
            if(p<=maxW/(ll)2) {
                cout << 'L';
                p=maxW/(ll)2-p+(ll)1;
            }
            else {
                cout<<'R';
                p=maxW-p+(ll)1;
            }

        }
        maxW/=(ll)2;
    }
    cout<<endl;

    return 0;
}