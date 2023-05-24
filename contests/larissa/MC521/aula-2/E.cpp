#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

string tratarPalavra(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    sort(word.begin(), word.end());
    return word;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string word;
    cin >> word;

    map<string, string> initialWord;
    set<string> ananograms;

    while(word != "#") {
        string newWord = tratarPalavra(word);

        if(initialWord.find(newWord) != initialWord.end()) {
            ananograms.erase(initialWord[newWord]);
        } else {
            initialWord[newWord] = word;
            ananograms.insert(word);
        }

        cin >> word;
    }

    for(set<string>::iterator it = ananograms.begin(); it != ananograms.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}