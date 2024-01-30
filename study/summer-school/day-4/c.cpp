#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    int t;cin>>t;
    
    while(t--) {
        int q,m;cin>>q>>m;
        int quest[q][4];
        memset(quest,-1,sizeof(quest));

        for(int i=0;i<m;i++) {
            for(int j=0;j<q;j++) {
                string v,r;cin>>v>>r;
                int num=0;
                if(v=="B") num=1;
                if(v=="C") num=2;
                if(v=="D") num=3;
                if(r=="T") quest[j][num]=1;
                if(r=="F") quest[j][num]=0;
                // cout<<j<<' '<<num<<endl;
            }
        }

        map<int,char> mapq;
        mapq[0]='A';
        mapq[1]='B';
        mapq[2]='C';
        mapq[3]='D';

        for(int i=0;i<q;i++) {
            bool found=false;
            int sumFalse=0;
            int notKnown=0;
            if(i>0) cout<<' ';
            for(int j=0;j<4;j++) {
                if(quest[i][j]==1) {
                    found=true;
                    cout<<mapq[j];
                    break;
                }
                if(quest[i][j]==0) {
                    sumFalse++;
                }

                if(quest[i][j]==-1) {
                    notKnown = j;
                }
            }
            if(!found) {
                if(sumFalse==3) {
                    cout<<mapq[notKnown];
                } else {
                    cout<<'?';
                }
            }
        }
        cout<<'\n';
    }

    return 0;
}
