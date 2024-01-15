#include <iostream>

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

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin>>s;
        int n=s.size();

        bool isOpen=true;
        bool failed=false;

        for(int i=0;i<n;i++) {
            if(isOpen&&s[i]==')') {
                isOpen=false;
            } else if(!isOpen&&s[i]=='(') {
                failed=true;
                break;
            }
        }

        if(failed) {
            cout<<"YES\n";
            for(int i=0;i<n;i++) {
                cout<<'(';
            }
            for(int i=0;i<n;i++) {
                cout<<')';
            }
            cout<<endl;
            continue;
        }

        if(n==2&&s=="()") {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        for(int i=0;i<n;i++) {
            cout<<"()";
        }
        cout<<endl;
    }

    return 0;
}