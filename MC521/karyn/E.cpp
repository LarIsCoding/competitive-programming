#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    string s;
    map<string, multiset<char>> mapa;
    vector<string> chaves;
    std::multiset<char> sett;
    std::set<string> ananagramas;
    while (cin >> s){
        if (s == "#") break;
        chaves.push_back(s);
        sett.clear();
        for (char x : s) sett.insert(tolower(x));
        mapa[s] = sett;
    }
    for (int i = 0; i < chaves.size(); i++){
        bool ananagrama = true;
        for (int k = 1; k < chaves.size(); k++){
            if (mapa[chaves[0]] == mapa[chaves[k]]) {
                ananagrama = false;
                break;
            }} 
        if (ananagrama == true) ananagramas.insert(chaves[0]);
        chaves.push_back(chaves[0]);
        chaves.erase(chaves.begin());
    }
    for (auto it = ananagramas.cbegin(); it != ananagramas.cend(); it++) {
        cout << *it << endl;
    }
    return 0;
}
