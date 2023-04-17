#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set <int> conjunto;
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++){
        int j;
        cin >> j;
        v[i]=j; }
    sort(v, v+n);
    for (int i = 0; i < n; i++){
        int j = v[i];
        if ((conjunto.find(j-1)  == conjunto.end()) && j-1 != 0) conjunto.insert(j-1);        
        else if (conjunto.find(j) == conjunto.end()) conjunto.insert(j);       
        else if (conjunto.find(j+1) == conjunto.end()) conjunto.insert(j+1); }
        
    int tamanho = conjunto.size();

    if (tamanho >= n) cout << n << endl;
    else cout << tamanho << endl;
    return 0;
}
