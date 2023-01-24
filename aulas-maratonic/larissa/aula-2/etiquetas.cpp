#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    map<string, string> dic;
    string language, phrase, name, aux;

    cin >> n;
    getline(cin, aux);

    for (int i = 0; i < n; i++) {
        getline(cin, language);
        getline(cin, phrase);
        dic[language] = phrase;
    }

    cin >> m;
    getline(cin, aux);

    for (int i = 0; i < m; i++) {
        getline(cin, name);
        getline(cin, language);
        cout << name << endl;
        cout << dic[language] << endl << endl;
    }

    return 0;
}