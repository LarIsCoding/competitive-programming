#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<int> numbers;

        for(int j = 0; j < n; j++) {
            int aux;
            cin >> aux;
            numbers.push_back(aux);
        }

        sort(numbers.begin(), numbers.end());

        int sum  = 0;

        int number = 0;
        for(int j = 0; j < n; j++) {
            if (numbers[j] != number) {
                number = numbers[j];
            } else {
                sum++;
            }
        }

        int left = n - sum - (sum % 2);

        cout << left << endl;
    }

    return 0;
}