#include <iostream>
#include <vector>
#include <map>
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

vector<pair<string,int> > seq[105];
int id[105];
map<string, int> finalVal;
map<string, bool> wasSet;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int total=0;
    for(int i=0;i<t;i++) {
        int l;cin>>l;
        id[i]=l-1;
        total+=l;

        for(int j=0;j<l;j++) {
            char c; cin>>c;
            vector<char> varChar;
            while(c!='=') {
                varChar.push_back(c);
                cin>>c;
            }
            string var(varChar.begin(),varChar.end());
            int val;cin>>val;
            seq[i].push_back(mp(var,val));
        }
    }

    int k;cin>>k;
    for(int i=0;i<k;i++) {
        string var;int val;
        cin>>var>>val;
        wasSet[var]=false;
        finalVal[var]=val;
    }

    stack<int> ans;
    while(total) {
        bool change=false;
        for(int i=0;i<t;i++) {
            if(id[i]<0) continue;

            string var=seq[i][id[i]].first;
            int val=seq[i][id[i]].second;

            if(wasSet[var] || finalVal[var]==val) {
                wasSet[var]=true;
                ans.push(i+1);
                total--;
                id[i]--;
                change=true;
            }
        }
        if(!change) {
            cout<<"No\n";
            return 0;
        }
    }

    cout<<"Yes\n";
    cout<<ans.top();
    ans.pop();
    while(!ans.empty()) {
        cout<<' ';
        cout<<ans.top();
        ans.pop();
    }
    cout<<endl;

    return 0;
}