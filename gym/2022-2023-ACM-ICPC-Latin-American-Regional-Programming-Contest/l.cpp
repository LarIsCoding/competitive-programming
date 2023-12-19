#include <iostream>
#include <vector>
#include <deque>

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

int n;
deque<char> s;
deque<int> z;

int z_function(int d) {
    int maxSize=min(d,n);

    for (int i = 1, l = 0, r = 0; i <= d && i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
        maxSize=max(z[i]+i,maxSize);
    }
    return maxSize;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int d;
    string aux;
    cin>>aux>>d;

    n=aux.size();

    for(int i=0;i<n;i++) {
        s.push_back(aux[i]);
        z.push_back(0);
    }

    int acc=0;
    while(n>0) {
        int x=z_function(d);
        for(int j=0;j<x;j++) {
            s.pop_front();
            z.pop_front();
        }
        acc++;
        n-=x;
    }

    cout<<acc<<endl;

    return 0;
}