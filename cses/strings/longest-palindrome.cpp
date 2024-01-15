#include <iostream>
#include <vector>

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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n=s.size();
    
    vi r=manacher(s);

    for(int i=0;i<r.size();i++) {
        cout<<r[i]<<' ';
    }cout<<endl;

    int best=0;
    int id=-1;
    for(int i=0;i<2*n-1;i++) {
        if(i%2) {
            int tam=((r[i]-1)/2)*2;
            if(tam>best) {
                best=tam;
                id=i/2 - tam/2;
            }
        } else {
            int tam=(r[i]/2 - 1)*2+1;
            if(tam>best) {
                best=tam;
                id=(i-1)/2 - tam/2;
            }
        }
    }

    for(int i=0;i<best;i++) {
        cout<<s[id+i];
    }
    cout<<endl;

    return 0;
}