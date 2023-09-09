#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string st;
    cin >> st;
    int n=st.size();

    string stz = st+st;

    vi z = z_function(stz);
    int count = 0;
    int find = -1;

    for(int i=0;i<n;i++) {
        if(st[i]=='(') count++;
        else {
            count--;
            if(count==0) {
                if(z[i+1]>=n) continue;
                find=i+1;
                break;
            }
        }
    }

    if(find==-1) {
        cout << "no\n";
    } else {
        for(int i=0;i<n;i++) {
            cout<<stz[find+i];
        }
        cout<<endl;
    }

    return 0;
}