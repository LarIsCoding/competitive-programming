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

    string s;
    cin >> s;
    int n=s.size();

    cout<<n<<endl;

    int num0=0,num1=0;

    int score=0;

    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            num1++;
            score+=num0;
        } else {
            num0++;
            score-=num1;
        }
    }
    // cout<<score<<endl;

    int total=0;

    while(score>0) {
        cout<<score<<endl;
        total++;
        int posIni=-1;
        int posFim=-1;

        for(int i=n-1;i>=0;i--) {
            if(s[i]=='1') {
                posIni=i;
                break;
            }
        }
        for(int i=0;i<n;i++) {
            if(s[i]=='0') {
                posFim=i;
                break;
            }
        }

        for(int i=posIni;i>=posFim;i--) {
            if(s[i]=='0') continue;

            posIni=i;
            int acc=0;
            for(int j=i-1;j>=posFim;j--) {
                acc+=2;
                if(s[j] == '0' && acc==score) {
                    posFim=j;
                    break;
                } else if(acc>score) {
                    break;
                }
            }

            if(acc>score) continue;
            score-=acc;
            s[posIni]='0';
            s[posFim]='1';
            break;
        }
    }

    while(score<0) {
        // cout<<score<<endl;
        total++;
        int posIni=-1;
        int posFim=-1;

        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                posIni=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='0') {
                posFim=i;
                break;
            }
        }

        for(int i=posIni;i<=posFim;i++) {
            if(s[i]=='0') continue;

            posIni=i;
            int acc=0;
            bool found=false;

            for(int j=i+1;j<=posFim;j++) {
                acc+=2;
                if(s[j] == '0' && acc==-score) {
                    posFim=j;
                    break;
                } else if(acc>-score) {
                    break;
                }
            }

            // cout<<i<<' '<<acc<<endl;

            if(acc>-score) continue;

            score+=acc;
            s[posIni]='0';
            s[posFim]='1';

            break;
        }
    }

    cout<<total<<endl;

    return 0;
}