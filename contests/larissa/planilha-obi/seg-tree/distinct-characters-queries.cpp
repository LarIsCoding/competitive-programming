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

struct Value {
    int quantity[26];
};

class SegmentTree {

    private:
    vector<Value> st; string A; // st -> indice do menor valor; A -> vetor com valores
    int n;

    int left(int p) {
        return p << 1;
    }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        memset(st[p].quantity, 0, sizeof st[p].quantity);
        if(L == R) {
            st[p].quantity[A[L]-'a']++;
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        for(int i=0;i<26;i++) {
            st[p].quantity[i]=p1.quantity[i]+p2.quantity[i];
        }
    }

    Value rmq(int p, int L, int R, int i, int j) {
        Value v;
        memset(v.quantity, 0, sizeof v.quantity);

        if(i > R || j < L) {
            return v;
        }
        if(L >= i && R <= j) return st[p];

        Value p1 = rmq(left(p), L, (L + R)/2, i, j);
        Value p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        for(int i=0;i<26;i++) {
            v.quantity[i]=p1.quantity[i]+p2.quantity[i];
        }
        return v;
    }

    void update(int p, int L, int R, int i, char v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            st[p].quantity[A[L]-'a']--;
            A[L] = v;
            st[p].quantity[A[L]-'a']++;
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        Value p1 = st[left(p)];
        Value p2 = st[right(p)];

        for(int i=0;i<26;i++) {
            st[p].quantity[i]=p1.quantity[i]+p2.quantity[i];
        }
    }

    public:
    SegmentTree(const string &_A) {
        A = _A;
        n = (int)A.size();
        st.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int i, int v) {
        update(1, 0, n - 1, i, v);
    }

    int rmq(int i, int j) {
        Value v = rmq(1, 0, n - 1, i, j);
        int total=0;
        for(int i=0;i<26;i++) {
            if(v.quantity[i]>0)total++;
        }
        return total;
    }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    SegmentTree st(s);

    int q;cin>>q;

    while(q--) {
        int op;cin>>op;
        if(op==1) {
            int i;char c;cin>>i>>c;i--;
            st.update(i,c);
        } else {
            int l,r;cin>>l>>r;l--;r--;
            cout << st.rmq(l,r)<<endl;
        }
    }

    return 0;
}