#include <iostream>
#include <vector>

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

bool eVogal(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n=s.size();

    int vogal=0,cons=0;
    vi v;

    bool isLastCons=false;
    int acc=0;

    for(int i=0;i<n;i++) {
        if(eVogal(s[i])) {
            if(isLastCons) {
                v.push_back(acc);
                acc=0;
                isLastCons=false;
                cons++;
            }
            vogal++;
        } else {
            acc++;
            isLastCons=true;
        }
    }

    if(acc>0) {
        v.push_back(acc);
        cons++;
    }

    if(vogal==0) {
        cout<<1<<endl;
        return 0;
    }

    if(!eVogal(s[0])) {
        cout<<0<<endl;
        return 0;
    }

    int r=1;
    int i=(vogal+1)/2 - 1;
    if(i<cons) {
        r+=v[i];
    }

    cout<<r<<endl;
    return 0;
}