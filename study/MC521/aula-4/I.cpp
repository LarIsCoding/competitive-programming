#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while(t--) {
        int n, aux;
        cin >> n;

        vi a;
        a.assign(n, 0);

        for(int i = 0; i < n; i++) {
            cin >> aux;
            a[i] = aux;
        }

        int intimidation = 0;
        vi b;
        b.assign(n, 0);

        for(int i = 1; i < n - 1; i++) {
            if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
                b[i] = 1;
                intimidation++;
            } else if(a[i] < a[i - 1] && a[i] < a[i + 1]) {
                b[i] = 2;
                intimidation++;
            }
        }

        bool achouDuplo = false;
        bool achouTriplo = false;

        for(int i = 1; i < n - 1; i++) {
            if(b[i] == 1 && b[i - 1] == 2 && b[i + 1] == 2) {
                achouTriplo = true;
                break;
            }
            if(b[i] == 2 && b[i - 1] == 1 && b[i + 1] == 1) {
                achouTriplo = true;
                break;
            }
            if(b[i] == 1 && (b[i - 1] == 2 || b[i + 1] == 2)) {
                achouDuplo = true;
            }
            if(b[i] == 2 && (b[i - 1] == 1 || b[i + 1] == 1)) {
                achouDuplo = true;
            }
        }

        if(achouTriplo) {
            intimidation -= 3;
        } else if(achouDuplo) {
            intimidation -= 2;
        } else if(intimidation > 0) {
            intimidation--;
        }

        cout << intimidation << '\n';
    }

    return 0;
}