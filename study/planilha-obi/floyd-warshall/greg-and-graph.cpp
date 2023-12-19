#include <iostream>
#include <vector>
#include <stack>

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

int d[505][505];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>d[i][j];
        }
    }

    int willDelete[n];
    for(int i=n-1;i>=0;i--) {
        cin>>willDelete[i];
    }

    stack<ll> st;

    for (int k = 0; k < n; ++k) {
        ll sum=0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int vi=willDelete[i];
                int vj=willDelete[j];
                int vk=willDelete[k];
                d[vi][vj] = min(d[vi][vj], d[vi][vk] + d[vk][vj]);
                if(i<=k && j<=k) sum += (ll)d[vi][vj];;
            }
        }
        st.push(sum);
    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
        if(!st.empty()) cout << ' ';
    }
    cout << endl;

    return 0;
}