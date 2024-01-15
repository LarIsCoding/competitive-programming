#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        set<char> light, heavy, regular;

        for(int j = 0; j < 3; j++) {
            string left, right, result;
            cin >> left >> right >> result;

            if(result == "even") {
                for(int k = 0; k < left.size(); k++) {
                    regular.insert(left[k]);
                    regular.insert(right[k]);
                }
            } else if(result == "up") {
                bool found[12];
                for(int i = 0; i < 12; i++) {
                    found[i] = false;
                }

                for(int k = 0; k < left.size(); k++) {
                    heavy.insert(left[k]);
                    light.insert(right[k]);
                    found[left[k] - 'A'] = true;
                    found[right[k] - 'A'] = true;
                }

                for(int i = 0; i < 12; i++) {
                    if(!found[i]) {
                        regular.insert('A' + i);
                    }
                }
            } else {
                bool found[12];
                for(int i = 0; i < 12; i++) {
                    found[i] = false;
                }

                for(int k = 0; k < left.size(); k++) {
                    light.insert(left[k]);
                    heavy.insert(right[k]);
                    found[left[k] - 'A'] = true;
                    found[right[k] - 'A'] = true;
                }

                for(int i = 0; i < 12; i++) {
                    if(!found[i]) {
                        regular.insert('A' + i);
                    }
                }
            }
        }

        set<char> light2, light3;
        set_difference(light.begin(), light.end(), heavy.begin(), heavy.end(), inserter(light2, light2.end()));
        set_difference(light2.begin(), light2.end(), regular.begin(), regular.end(), inserter(light3, light3.end()));

        set<char> heavy2, heavy3;
        set_difference(heavy.begin(), heavy.end(), light.begin(), light.end(), inserter(heavy2, heavy2.end()));
        set_difference(heavy2.begin(), heavy2.end(), regular.begin(), regular.end(), inserter(heavy3, heavy3.end()));

        if(light3.size() > 0) {
            cout << *light3.begin() << " is the counterfeit coin and it is light.\n";
        } else {
            cout << *heavy3.begin() << " is the counterfeit coin and it is heavy.\n";
        }
    }

    return 0;
}