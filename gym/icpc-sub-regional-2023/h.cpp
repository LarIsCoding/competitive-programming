#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;
typedef vector<ll> vi;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e19;

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
        // cout<<L<<' '<<R<<endl;
        if(L == R) {
            st[p] = A[L];
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        ll p1 = st[left(p)];
        ll p2 = st[right(p)];

        // cout<<L<<' '<<R<<endl;
        // cout<<p1<<' '<<A[p1]<<' '<<p2<<' '<<A[p2]<<endl;

        st[p] = min(p1,p2);
    }

    ll rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return st[p];

        ll p1 = rmq(left(p), L, (L + R)/2, i, j);
        ll p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;

        // cout<<p1<<' '<<A[p1]<<' '<<p2<<' '<<A[p2]<<endl;
        return min(p1,p2);
    }

    void update(int p, int L, int R, int i, ll v) {
        if(i > R || i < L) return;

        if(i == L && i == R) {
            st[p] = v;
            A[L] = v;
            return;
        }

        update(left(p), L, (L + R)/2, i, v);
        update(right(p), (L + R)/2 + 1, R, i, v);

        ll p1 = st[left(p)];
        ll p2 = st[right(p)];

        st[p] = min(p1,p2);
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void update(int i, ll v) {
        update(1, 0, n - 1, i, v);
    }

    ll rmq(int i, int j) {
        return rmq(1, 0, n - 1, i, j);
    }
};

struct Job {
    int id, l, r, c;
    bool isOpen;
};

Job job[(int)2e6+5];
ll memo[(int)1e6+5];
vi sum;

bool cmp(Job j1, Job j2) {
    if(j1.isOpen && j2.isOpen) return j1.l < j2.l;
    if(j1.isOpen && !j2.isOpen) return j1.l <= j2.r;
    if(!j1.isOpen && j2.isOpen) return j1.r < j2.l;
    return j1.r < j2.r;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,s;
    cin >> n>>s;

    for(int i=0;i<n;i++) {
        int l,r,c;cin>>l>>r>>c;
        job[2*i]=(Job){i,l,r,c,true};
        job[2*i+1]=(Job){i,l,r,c,false};
    }


    sort(job,job+2*n,cmp);
    sum.assign(n,linf);

    SegmentTree st(sum);

    ll best=0;
    ll end = job[2*n-1].r;

    for(int i=2*n-1;i>=0;i--) {
        Job j=job[i];
        if(!j.isOpen) {
            int add=(j.r-j.l+1)*s;
            // cout<<add<<endl;

            ll remove1 = (end - j.r)*s + j.c - best;
            ll remove2 = st.rmq(0,n-1);

            // cout<<remove2<<endl;
            // cout<<linf<<endl;

            if(remove2 == linf) {
                st.update(j.id, remove1);
                // cout<<remove1<<endl;
                // cout<<st.rmq(0,n-1)<<endl;
                memo[j.id]=best+add-j.c;
                // cout<<j.id<<' '<<memo[j.id]<<' '<<best<<endl;
                continue;
            }

            // cout<<remove1<<endl;
            // cout<<remove2<<endl;

            remove2 += j.c;

            ll bestChoice = min(remove1, remove2);
            st.update(j.id, bestChoice);

            memo[j.id]=(end - j.l + 1)*s - bestChoice;

        } else {
            best=max(best,memo[j.id]);
            st.update(j.id,linf);
        }
        // cout<<j.id<<' '<<memo[j.id]<<' '<<best<<endl;
    }

    cout<<best<<endl;

    return 0;
}