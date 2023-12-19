#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const int linf = (int)1e17;

ii memo[(int)1e5+5];

struct Node {
    int func, min, max, val;
};

struct Query {
    int id, l, r, x, ans;
};

Query queries[(int)1e5+5];

class SegmentTree {

    private:
    vector<Node> st;
    vi A; // st -> indice do menor valor; A -> vetor com valores
    int l, u;
    int size;

    int left(int p) {
        return p << 1;
    }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if(L == R) {
            int func=A[L];
            int xMin=(func>0)?-inf:(l-func);
            int xMax=(func<0)?inf:(u-func);
            int val=(func>0)?u:l;
            st[p] = (Node){func,xMin,xMax,val};
            return;
        }

        build(left(p), L, (L + R)/2);
        build(right(p), (L + R)/2 + 1, R);

        Node p1 = st[left(p)];
        Node p2 = st[right(p)];

        int func=p1.func+p2.func;
        func=min(u,func);
        func=max(-u,func);

        int xMin=min(max(p1.min,max(l-func,p2.min-p1.func)),u+1);
        int xMax=max(min(p1.max,min(u-func,p2.max-p1.func)),l-1);

        int val;
        if(p1.val<p2.min) val = p2.val;
        else if(p1.val>p2.max) val = p2.val;
        else val = p1.val+p2.func;

        st[p] = (Node){func,xMin,xMax,val};
    }

    Node rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return (Node){inf,0,0,0};
        if(L >= i && R <= j) {
            // cout<<"lntervalo: "<<L<<' '<<R<<' '<<endl;
            // cout<<st[p].func<<' '<<st[p].min<<' '<<st[p].max<<' '<<st[p].val<<endl;
            return st[p];
        }

        Node p1 = rmq(left(p), L, (L + R)/2, i, j);
        Node p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1.func == inf) return p2;
        if(p2.func == inf) return p1;

        int func=p1.func+p2.func;
        func=min(u,func);
        func=max(-u,func);

        int xMin=min(max(p1.min,max(l-func,p2.min-p1.func)),u+1);
        int xMax=max(min(p1.max,min(u-func,p2.max-p1.func)),l-1);

        int val;
        if(p1.val<p2.min || p1.val>p2.max) {
            val = p2.val;
            val = rmq(i, j, p1.val);
        }
        else val = p1.val+p2.func;

        // cout<<"lntervalo: "<<L<<' '<<R<<' '<<endl;
        // cout<<func<<' '<<xMin<<' '<<xMax<<' '<<val<<endl;

        return (Node){func,xMin,xMax,val};
    }

    public:
    SegmentTree(const vi &_A, int _l, int _u) {
        A = _A;
        l=_l;
        u=_u;
        size = (int)A.size();
        st.resize(4 * size);
        build(1, 0, size - 1);
    }

    int rmq(int i, int j, int x) {
        int i1=i, j1=j;
        while(i1<j1) {
            int m=(i1+j1)/2;
            Node n = rmq(1, 0, size - 1, i, m);
            if(x<n.min||x>n.max) j1=m;
            else i1=m+1;
        }

        // cout<<i1<<endl;

        int val;

        Node n = rmq(1, 0, size - 1, i, i1);
        
        if(x<n.min||x>n.max) {
            if(memo[i1].f!=-1) {
                if(memo[i1].s==j) return memo[i1].f;
                int val = rmq(memo[i1].s+1, j, memo[i].f);
                // cout<<val<<endl;
                memo[i1]=mp(val,j);
                return val;
            }

            n = rmq(1, 0, size - 1, i1, i1);
            if(i1<j) {
                val = rmq(i1+1, j, n.val);
            } else {
                val = n.val;
            }
        } else {
            val=x+n.func;
            // cout<<val<<endl;
        }

        return val;
    }
};

vi v;

bool cmp1(Query q1, Query q2) {
    return q1.r<q2.r;
}

bool cmp2(Query q1, Query q2) {
    return q1.id<q2.id;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,l,u;
    cin >> n>>l>>u;

    v.resize(n);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    SegmentTree st(v,l,u);

    int q;cin>>q;

    for(int i=0;i<q;i++) {
        int l,r,x;cin>>l>>r>>x;
        Query qu={i,l-1,r-1,x,-1};
        queries[i]=qu;
    }

    sort(queries,queries+q,cmp1);
    memset(memo,-1,sizeof memo);

    for(int i=0;i<q;i++) {
        // cout<<"Query: "<<queries[i].id<<endl;
        queries[i].ans=st.rmq(queries[i].l,queries[i].r,queries[i].x);
    }

    sort(queries,queries+q,cmp2);

    for(int i=0;i<q;i++) {
        cout<<queries[i].ans<<endl;
    }

    return 0;
}