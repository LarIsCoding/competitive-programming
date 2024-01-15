#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n != 0) {

        set<string> species;

        for (int i = 0; i < n; i++) {
            string sequence;
            cin >> sequence;
            
            int bases[16];
            for(int j = 0; j < 16; j++) {
                bases[j] = 0;
            }

            for(int j = 0; j < sequence.size(); j++) {
                bases[sequence[j] - 'A']++;
            }

            string res = "";
            for(int j = 0; j < 16; j++) {
                res += to_string(bases[j]) += "-";
            }

            species.insert(res);
        }
        cout << species.size() << endl;
        cin >> n;
    }

    return 0;
}