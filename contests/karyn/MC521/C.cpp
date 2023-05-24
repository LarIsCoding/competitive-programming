#include <bits/stdc++.h>
#include <deque>
#include <string.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    while (1){
    string s;
    getline(cin, s);
    if (s == "DONE") break;
    else{
        deque<char> d;
        char c;
        int n = s.size();
        int k = n;
        for (int i = 0; i<k; i++){
            c = tolower(s[i]);
            if (!(c == '.' || c == ' '|| c == ',' || c == '!' || c == '?')) d.push_back(c);
        }
        if (d.empty()) cout << "You won't be eaten!" << endl;
        while (!d.empty()){
            if (d.front() != d.back()){
                cout << "Uh oh.." << endl;
                break;
            }
            else {
                if (d.size() <= 1){ 
                    cout << "You won't be eaten!" << endl;
                    break; 
                    }
                else{
                    d.pop_back();
                    d.pop_front();
                    if (d.empty()) {
                        cout << "You won't be eaten!" << endl;
                        break;
                    }
                }
            }
        }
    }
}
}
