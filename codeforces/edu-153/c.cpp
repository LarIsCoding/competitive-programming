#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin>>n;

        int r=0;
        int menor;
        cin>>menor;
        int last=-1;

        for(int i=0;i<n-1;i++) {
            int aux;cin>>aux;
            if(aux>menor&&last==-1) {
                last=aux;
                r++;
            } else if(aux<last&&aux>menor) {
                r++;
                last=aux;
            }
            menor=min(menor,aux);
        }
        cout<<r<<endl;
    }

    return 0;
}