#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

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

    int parent(int p) {
        return p >> 1;
    }

    void build(int p, int L, int R) {
        if(L == R) {
            st[p] = (A[L] == 0) ? 0 : A[L]/abs(A[L]);
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        int p1 = st[left(p)];
        int p2 = st[right(p)];
        st[p] = p1 * p2;
    }

    void update(int p, int L, int R, int i, int v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            st[p] = (v == 0) ? 0 : v/abs(v);
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        st[p] = p1 * p2;
    }

    int rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return -2;
        if(L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L + R)/2, i, j);
        int p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1 == -2) return p2;
        if(p2 == -2) return p1;
        return p1 * p2;
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void update(int i, int v) {
        update(1, 0, n - 1, i - 1, v);
    }

    int rmq(int i, int j) {
        return rmq(1, 0, n - 1, i - 1, j - 1);
    }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    while(cin >> n >> k) {
        vi x;
        x.assign(n, 0);

        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }

        SegmentTree st(x);

        for(int i = 0; i < k; i++) {
            char c;
            cin >> c;

            if(c == 'C') {
                int id, v;
                cin >> id >> v;
                st.update(id, v);
            } else {
                int l, r;
                cin >> l >> r;
                int result = st.rmq(l, r);
                if(result == 1) cout << '+';
                else if(result == -1) cout << '-';
                else cout << '0';
            }
        }
        cout << endl;
    }

    return 0;
}