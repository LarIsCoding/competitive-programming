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

    string s;
    cin >> s;
    int n=s.size();
    s=s+s;

    int ini=0;
    int pot=0;
    bool process=false;
    for(int i=1;i<2*n;i++) {
        if(s[i]<s[ini]) {
            ini=i;
            process=false;
        }
        else if(process) {
            int diff=i-pot;
            if(s[i]<s[ini+diff]) {
                ini=pot;
                process=false;
            } else if(s[i]>s[ini+diff]) {
                process=false;
            }
        }
        else if(s[i]==s[ini]) {
            pot=i;
            process=true;
        }
    }

    for(int i=0;i<n;i++) {
        cout<<s[(ini+i)%n];
    }
    cout<<endl;

    return 0;
}