#include <iostream>
#include <vector>
#include <cstring>

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

const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}

string s;
int n;

int memo[5000];

int dp(int i) {
    if(i==n) return 1;
    if(memo[i]!=-1)return memo[i];

    int acc=0;
    int v = 0;
    
    for (int j=i;j<n;j++) {
        char ch=s[j];
        int c = ch - 'a';
        if (trie[v].next[c] == -1) break;
        v = trie[v].next[c];
        if(trie[v].output) acc = (acc+dp(j+1))%mod;
    }

    return memo[i]=acc;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>s;
    n=s.size();

    int m;
    cin >> m;

    for(int i=0;i<m;i++) {
        string x;cin>>x;
        add_string(x);
    }

    memset(memo,-1,sizeof memo);
    cout<<dp(0)<<endl;

    return 0;
}
