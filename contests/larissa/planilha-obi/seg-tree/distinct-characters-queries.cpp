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
}

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
        memset(st[p], 0, sizeof st[p]);
        if(L == R) {
            st[p].quantity[A[L]-'a']++;
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        for(int i=0;i<26;i++) {
            st[p].quantity[i]=st[p1].quantity[i]+st[p2].quantity[i];
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L + R)/2, i, j);
        int p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    void update(int p, int L, int R, int i, char v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            st[p][A[L]-'a']--;
            A[L] = v;
            st[p][A[L]-'a']++;
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        for(int i=0;i<26;i++) {
            st[p].quantity[i]=st[p1].quantity[i]+st[p2].quantity[i];
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
        return rmq(1, 0, n - 1, i, j);
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