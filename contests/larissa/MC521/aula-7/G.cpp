#include <iostream>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        bool encontrou0 = false;
        bool saiuDo0 = false;

        int r = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                r = 1;
                encontrou0 = true;
                if(saiuDo0) {
                    r = 2;
                    break;
                }
            } else {
                if(encontrou0) {
                    saiuDo0 = true;
                }
            }
        }

        cout << r << endl;
    }

    return 0;
}