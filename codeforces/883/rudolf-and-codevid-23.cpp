#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int readBin(int n) {
    char aux;
    int num = 0;
    for(int i = n-1;i>=0;i--) {
        cin>>aux;
        num|=(int)(aux - '0')<<i;
    }
    return num;
}

int applyMedicine(int symptoms, int remove, int add, int num) {
    int res=0;
    for(int i=0;i<num;i++) {
        int s=(symptoms&(1<<i))>>i;
        int r=(remove&(1<<i))>>i;
        int a=(add&(1<<i))>>i;
        if((s & !r) | a) {
            res |= 1<<i;
        }
    }
    return res;
}

int med[(int)1e3+5][3];
bool wasSet[(int)1e4];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;cin>>n>>m;
        int from = readBin(n);
        for(int i=0;i<m;i++) {
            cin >> med[i][0];
            med[i][1] = readBin(n);
            med[i][2] = readBin(n);
        }

        memset(wasSet, false, sizeof(wasSet));
        
        int time=0;
        priority_queue<ii, vector<ii>, greater<ii> > q;
        q.push(mp(time, from));

        while(!q.empty() && q.top().second != 0) {
            ii v=q.top();q.pop();
            if(wasSet[v.second]) continue;
            wasSet[v.second] = true;
            for(int i=0;i<m;i++) {
                int r = applyMedicine(v.second, med[i][1], med[i][2], n);
                q.push(mp(v.first+med[i][0], r));
            }
        }

        if(q.top().second==0) {
            cout << q.top().first << endl;
        } else {
            cout << -1<< endl;
        }
    }

    return 0;
}