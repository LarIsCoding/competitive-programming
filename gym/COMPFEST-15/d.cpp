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

#define FOR(i, b) for(int i = 0; i < b; i++)

template <class T>
struct FT { // Indexed by 0
  int n;
  vector<T> bit;

  FT(int n, int ini): n(n), bit(n, ini){}

  T sum(int r) {
    T ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  void add(int i, T val) {
    for (; i < n; i |= i + 1)
      bit[i] += val;
  }

  T Query(int pos) {
    return sum(pos);
  }

  void Add(int l, int r, T val){
    add(l, val);
    add(r + 1, -val);
  }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    FT<int> ft(m,k);
    priority_queue<ii> pq;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int aux;cin>>aux;
            pq.push({aux,j});
        }
    }

    ll acc=0;
    for(int i=0;i<m-k+1;i++) {
        int c=pq.top().second;
        int val=pq.top().first;
        pq.pop();
        if(ft.Query(c)<=0) {
            i--;
            continue;
        }
        acc+=(ll)val;
        ft.Add(max(c-k+1,0), min(m-1,c+k-1), -1);
    }

    cout<<acc<<endl;

    return 0;
}