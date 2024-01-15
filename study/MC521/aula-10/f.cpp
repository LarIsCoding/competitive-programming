#include <iostream>
#include <stack>
#include <map>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int k = 1; k <= t; k++) {
        string s;cin>>s;

        stack<char> st; st.push(s[0]);
        map<char, int> adj;
        adj[s[0]] = 0;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == st.top()) {
                st.pop();continue;
            }
            adj[st.top()]++;
            adj[s[i]] = 1;
            st.push(s[i]);
        }

        cout << "Case " << k << endl;
        for(auto it : adj) {
            if(it.first)
            cout << it.first << " = " << it.second << endl;
        }
    }

    return 0;
}