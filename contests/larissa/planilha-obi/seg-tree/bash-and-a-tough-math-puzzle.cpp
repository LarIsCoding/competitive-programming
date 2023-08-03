#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,bool> ib;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int mdc(int num1, int num2) {
    if(num2>num1) swap(num1,num2);
    int resto;
    do {
        resto = num1 % num2;
        num1 = num2;
        num2 = resto;
    } while (resto != 0);
    return num1;
}

class SegmentTree {

    private:
    vi st, A; // st -> indice do menor valor; A -> vetor com valores
    int n;

    int left(int p) {
        return p << 1;
    }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if(L == R) {
            st[p] = A[L];
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        st[p] = mdc(p1,p2);
    }

    ib rmq(int p, int L, int R, int i, int j, int x, bool found) {
        // cout << i << ' ' << j << ' ' << L <<' '<<R<<endl;
        if(i > R || j < L) return mp(-1,false);
        if(L >= i && R <= j) {
            if(st[p]%x==0) return mp(st[p],false);
            else if(found) return mp(0,true);
            else if(L==R) return mp(st[p],false);
        }

        ib p1 = rmq(left(p), L, (L + R)/2, i, j, x, found);
        if(p1.s) return mp(0,true);
        if(p1.f != -1) found |= p1.f%x;
        ib p2 = rmq(right(p), (L + R)/2 + 1, R, i, j, x, found);
        if(p2.s) return mp(0,true);

        // cout << p1.f << ' ' << p2.f << endl;

        if(p1.f == -1) return mp(p2.f,false);
        if(p2.f == -1) return mp(p1.f,false);
        return mp(mdc(p1.f,p2.f),false);
    }

    void update(int p, int L, int R, int i, int v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            A[L] = v;
            st[p] = A[L];
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        st[p] = mdc(p1,p2);
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void update(int i, int v) {
        update(1, 0, n - 1, i, v);
    }

    int rmq(int i, int j, int x) {
        return rmq(1, 0, n - 1, i, j, x, false).second;
    }
};

vi v;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    v.assign(n,0);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    SegmentTree st(v);

    int q;cin>>q;

    while(q--) {
        int op;cin>>op;
        if(op==1) {
            int l,r,x;cin>>l>>r>>x;l--;r--;
            string res = st.rmq(l,r,x) ? "NO\n" : "YES\n";
            cout<<res;
        } else {
            int i,y;cin>>i>>y;i--;
            st.update(i,y);
        }
    }

    return 0;
}