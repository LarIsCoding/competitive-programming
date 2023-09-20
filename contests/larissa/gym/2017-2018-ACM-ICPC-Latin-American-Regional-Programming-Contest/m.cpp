#include <iostream>
#include <vector>
#include <set>
#include <math.h>

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

vector<int> sort_cyclic_shifts(vi const& s) {
    int n = s.size();
    const int alphabet = 305;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = mp(c[p[i]], c[(p[i] + (1 << h)) % n]);
            pair<int, int> prev = mp(c[p[i-1]], c[(p[i-1] + (1 << h)) % n]);
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(vi &s) {
    s.push_back(0);
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int pot[(int)5e5+5];

vi marble;
int top[(int)1e5+5];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int t=0;
    int total=0;
    for(int i=0;i<n;i++) {
        top[i]=t;
        int k;cin>>k;
        for(int j=0;j<k;j++) {
            int x;cin>>x;
            marble.push_back(x);
        }
        marble.push_back(301);
        t+=k+1;
        total+=k;
    }

    vi r=suffix_array_construction(marble);

    vi inv(t);
    for(int i=0;i<t;i++) {
        inv[r[i]]=i;
    }

    set<ii> av;

    for(int i=0;i<n;i++) {
        av.insert(mp(inv[top[i]],i));
    }

    ll x=1;
    for(int i=1;i<=total;i++) {
        x=(x*(ll)365)%mod;
        pot[i]=x;
    }

    ll ans=0;
    for(int i=total;i>0;i--) {
        auto best=av.begin();
        ans+=((ll)marble[top[best->s]]*(ll)pot[i])%mod;
        top[best->s]++;
        if(marble[top[best->s]] < 301) av.insert(mp(inv[top[best->s]],best->s));
        av.erase(best);
    }

    cout<<ans%mod<<endl;

    return 0;
}