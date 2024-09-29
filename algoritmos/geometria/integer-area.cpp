ll area(vector<ii> &v) {
    ll a=0;
    int n=v.size();
    for(int i=0;i<n;i++) {
        a+=(ll)v[i].f*(ll)v[(i+1)%n].s;
        a-=(ll)v[i].s*(ll)v[(i+1)%n].f;
    }
    return abs(a/2);
}

// A = I + B/2 - 1
// Onde A é área, I é o número de pontos internos e B é o número de pontos na borda
ll picks_formula(ll a, ll b) {
    return a - b/2 + 1;
}