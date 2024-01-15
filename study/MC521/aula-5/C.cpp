#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<char, int> ci;
typedef vector<ci> vci;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    vci states;
    states.reserve(s.size());

    for(int i = 0; i < s.size(); i++) {
        states.push_back(make_pair(s[i], i));
    }

    sort(states.begin(), states.end());

    int t;
    cin >> t;

    while(t--) {
        string ss;
        cin >> ss;

        int index = -1, first = -1, last = -1;
        bool falhou = false;

        for(int i = 0; i < ss.size(); i++) {

            vci::iterator found = upper_bound(states.begin(), states.end(), make_pair(ss[i], index));

            if(found == states.end() || found->first != ss[i]) {
                falhou = true;
                break;
            }

            if(i == 0) first = found->second;
            if(i == ss.size() - 1) last = found->second;

            index = found->second;
        }

        if(falhou) cout << "Not matched\n";
        else cout << "Matched " << first << ' ' << last << endl;
    }

    return 0;
}