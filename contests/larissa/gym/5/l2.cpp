#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int inf=1e9;

bool memo[51][505][505];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,a,b,c;
    cin>>n>>a>>b>>c;

    for(int i=0;i<51;i++) {
        for(int j=0;j<505;j++) {
            memset(memo[i][j],false,sizeof memo[i][j]);
        }
    }
    memo[0][0][0]=true;

    int total=0;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        total+=x;
        for(int valA=0;valA<505;valA++) {
            for(int valB=0;valB<505;valB++) {
                if(!memo[i-1][valA][valB]) continue;
                memo[i][valA+x][valB]=true;
                memo[i][valA][valB]=true;
                memo[i][valA][valB+x]=true;
            }
        }
    }

    int minTempo = inf;
    for(int valA=0;valA<505;valA++) {
        for(int valB=0;valB<505;valB++) {
            if(!memo[n][valA][valB]) continue;
            int valC = total-valA-valB;
            int timeA=ceil((double)valA/(double)a);
            int timeB=ceil((double)valB/(double)b);
            int timeC=ceil((double)valC/(double)c);
            int tempo = max(timeA, max(timeB, timeC));
            minTempo = min(minTempo, tempo);
        }
    }

    cout << minTempo << endl;

    return 0;
}