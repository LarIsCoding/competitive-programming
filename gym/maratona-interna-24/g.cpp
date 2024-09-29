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
#define EPS 1e-9

void dbg_out() {cerr << endl; }
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) {cerr << #__VA_ARGS__ << ':' ; dbg_out(__VA_ARGS__); } 

set<ll> v;
queue<ll> st;

void printV() {
    for(auto it:v) {
        cout<<it<<' ';
    }
    cout<<endl;
}

bool tenta(ll pos, ll x) {
    if(x==-1) {
        if(pos!=*v.begin()||v.size()!=1) return false;
        st.push(pos);
        return true;
    }
    auto it=v.end();
    it--;
    if(pos>*v.begin()&&pos<*it) {
        return false;
    }
    ll newPos;
    if(pos<=*v.begin()) {
        if(pos==*v.begin()) {
            v.erase(pos);
            newPos = pos+pow(2,x);
            if(tenta(newPos, x-1)) {
                st.push(pos);
                return true;
            }
            v.insert(pos);
            return false;
        } else {
            newPos = pos+pow(2,x);
            if(tenta(newPos, x-1)) {
                st.push(pos);
                return true;
            }
            return false;
        }
    } else {
        auto it=v.end();
        it--;
        if(pos==*it) {
            v.erase(pos);
            newPos = pos-pow(2,x);
            if(tenta(newPos, x-1)) {
                st.push(pos);
                return true;
            }
            v.insert(pos);
            return false;
        } else {
            newPos = pos-pow(2,x);
            if(tenta(newPos, x-1)) {
                st.push(pos);
                return true;
            }
            return false;
        }
    }
}

void solve() {
    int n;cin>>n;
    v.clear();

    for(int i=0;i<n;i++) {
        ll x;cin>>x;
        v.insert(x);
    }

    for(int i=-1;i<=50;i++) {
        if(tenta(*v.begin(),i)) {
            break;
        }
        auto it=v.end();
        it--;
        if(tenta(*it,i)) {
            break;
        }
    }

    cout<<st.size()<<endl;
    while(!st.empty()) {
        cout<<st.front();
        st.pop();
        if(!st.empty()) cout<<' ';
    }
    cout<<'\n';
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i=0;i<t;i++) {
        solve();
    }

    return 0;
}