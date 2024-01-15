#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

vector<int> numbers;

bool isNumber(char c) {

}

bool isSeparator(char c) {

}

void getNumbers(string line) {
    deque<int> acc;
    bool isLastNumber = false;
    bool isLastSeparator = true;

    for(int i = 0; i < line.length(); i++) {
        char c = line[i];

        if(isNumber(c)) {
            if(isLastSeparator || isLastNumber) {
                acc.push_back(c);
            }
            isLastNumber = true;
            isLastSeparator = false;
        } else if(isSeparator(c)) {
            if(isLastSeparator) {
                numbers.push(toInt(acc));
                acc.clear()
            }
            isLastNumber = false;
            isLastSeparator = true;
        }
    }
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string linha;
        cin.getline(linha);
        getNumbers(linha);
    }



    return 0;
}