#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int inf=1e9;

vi memo[51][505];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,a,b,c;
    cin>>n>>a>>b>>c;

    memo[0][0].push_back(0);

    int total=0;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        total+=x;
        for(int valA=0;valA<505;valA++) {
            for(auto valB : memo[i-1][valA]) {
                memo[i][valA+x].push_back(valB);
                memo[i][valA].push_back(valB);
                memo[i][valA].push_back(valB+x);
            }
        }
    }

    int minTempo = inf;
    for(int valA=0;valA<505;valA++) {
        for(auto valB : memo[n][valA]) {
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