#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<long double,bool> db;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;
const long double epsilon = 1e-11;

vector<ii> points;
int n;
pair<ii, db> retas[3];
bool temPonto[3];
bool temReta[3];

db findIncl(ii a, ii b) {
    // retorna true quando é uma reta vertical (inclinação infinita)
    if(a.f==b.f) return mp(0,true);
    
    return mp((long double)(a.s-b.s)/(long double)(a.f-b.f),false);
}

bool tenta(int p) {
    if(p==n) return true;
    // tenta encaixar em uma reta que já tem ponto e inclinação
    for(int i=0;i<3;i++) {
        if(temReta[i]) {
            ii a=retas[i].f, b=points[p];
            db incl = findIncl(retas[i].f, points[p]);
            bool isVert = incl.s && retas[i].s.s;
            bool notIsVert = !incl.s && !retas[i].s.s;
            if(a.s==b.s&&a.f==b.f) return tenta(p+1);
            if(isVert || (notIsVert && fabs(incl.f-retas[i].s.f)<epsilon)) return tenta(p+1);
        }
    }
    // tenta encaixar em uma reta que só tem ponto
    for(int i=0;i<3;i++) {
        if(temPonto[i]) {
            ii a=retas[i].f, b=points[p];
            if(a.s==b.s&&a.f==b.f) return tenta(p+1);
            db incl = findIncl(retas[i].f, points[p]);
            retas[i].s=incl;
            temReta[i]=true;
            temPonto[i]=false;
            if(tenta(p+1)) return true;
            temReta[i]=false;
            temPonto[i]=true;
        }
    }
    // define uma nova reta (caso haja espaço sobrando)
    for(int i=0;i<3;i++) {
        if(!temPonto[i] && !temReta[i]) {
            retas[i].f=points[p];
            temPonto[i]=true;
            if(tenta(p+1)) return true;
            temPonto[i]=false;
            return false;
        }
    }
    return false;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        int x,y;cin>>x>>y;
        points.push_back(mp(x,y));
    }

    temPonto[0]=false;
    temPonto[1]=false;
    temPonto[2]=false;
    temReta[0]=false;
    temReta[1]=false;
    temReta[2]=false;

    if(tenta(0)) {
        cout << "possible\n";
    } else {
        cout << "impossible\n";
    }

    return 0;
}