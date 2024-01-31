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

int c[4];
int win[4];
bool emp[4];

int match[4][4];

void solve(int t) {
    cin>>c[0]>>c[1]>>c[2]>>c[3];

    bool found=false;

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            for(int k=0;k<3;k++) {
                for(int l=0;l<3;l++) {
                    for(int m=0;m<3;m++) {
                        for(int n=0;n<3;n++) {
                            memset(win,0,sizeof win);

                            if(i==0) win[0]+=3;
                            else if(i==1) win[1]+=3;
                            else {
                                win[0]++;
                                win[1]++;
                            }

                            if(j==0) win[0]+=3;
                            else if(j==1) win[2]+=3;
                            else {
                                win[0]++;
                                win[2]++;
                            }

                            if(k==0) win[0]+=3;
                            else if(k==1) win[3]+=3;
                            else {
                                win[0]++;
                                win[3]++;
                            }

                            if(l==0) win[1]+=3;
                            else if(l==1) win[2]+=3;
                            else {
                                win[1]++;
                                win[2]++;
                            }

                            if(m==0) win[1]+=3;
                            else if(m==1) win[3]+=3;
                            else {
                                win[1]++;
                                win[3]++;
                            }

                            if(n==0) win[2]+=3;
                            else if(n==1) win[3]+=3;
                            else {
                                win[2]++;
                                win[3]++;
                            }

                            bool failed=false;
                            for(int x=0;x<4;x++) {
                                if(win[x]!=c[x]) failed=true;
                            }
                            if(!failed) {
                                if(found) {
                                    cout<<"Case #"<<t<<": No\n";
                                    return;
                                }
                                found=true;
                            }
                        }
                    }
                }
            }
        }
    }
    if(found) {
        cout<<"Case #"<<t<<": Yes\n";
    } else {
        cout<<"Case #"<<t<<": Wrong Scoreboard\n";
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i=1;i<=t;i++) {
        solve(i);
    }

    return 0;
}