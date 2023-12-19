#include <iostream>
#include <map>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int a[(int)5e5+5];
int s[(int)5e5+5];
int p[(int)5e5+5];

map<int, int> q;

bool preenche(int i, int n) {
    int comp = s[i - 1] - p[i - 1];
    if(q.find(comp) == q.end()) return false;
    q[comp]--;
    p[i] = comp;
    if(i == n-1) return true;
    if(preenche(i+1, n)) return true;
    q[comp]++;
    return false;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(q.find(a[i]) == q.end()) {
            q[a[i]] = 1;
        } else{
            q[a[i]]++;
        }
    }
    for(int i = 0; i < n-1; i++) {
        cin >> s[i];
    }

    for(int i = 0; i < n; i++) {
        q[a[i]]--;
        p[0] = a[i];
        if(preenche(1, n)) break;
        q[a[i]]++;
    }

    bool space = false;
    for(int i = 0; i < n; i++) {
        if(space) cout << ' ';
        cout << p[i];
        space = true;
    }
    cout << endl;

    return 0;
}