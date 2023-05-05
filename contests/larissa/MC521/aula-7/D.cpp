#include <iostream>

using namespace std;

typedef long long int ll;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        int digit = 0;
        bool found0 = false;
        bool found5 = false;
        int acc = 0;

        while(true) {
            digit = n % 10;
            n = n / (ll)10;

            if(digit == 0) {
                if(!found0) {
                    found0 = true;
                } else {
                    if(found5) acc++;
                    cout << acc << endl;
                    break;
                }

            } else if(digit == 5) {
                if(found0) {
                    if(found5) acc++;
                    cout << acc << endl;
                    break;
                }
                if(!found5) {
                    found5 = true;
                } else {
                    acc++;
                }

            } else if(digit == 2) {
                if(found5) {
                    if(found0) acc++;
                    cout << acc << endl;
                    break;
                } else {
                    acc++;
                }

            } else if(digit == 7) {
                if(found5) {
                    if(found0) acc++;
                    cout << acc << endl;
                    break;
                } else {
                    acc++;
                }
            } else {
                acc++;
            }
        }
    }

    return 0;
}