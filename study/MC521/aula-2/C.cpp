#include <iostream>
#include <deque>

using namespace std;

bool isValid(char c) {
    char notValid[] = {'.', ',', '!', '?', ' '};

    for(int i = 0; i < 5; i++) {
        if(c == notValid[i]) return false;
    }

    return true;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string phrase;
    getline(cin, phrase);

    while(phrase != "DONE") {
        deque<char> sentence;

        for(int i = 0; i < phrase.size(); i++) {
            if(isValid(phrase[i])) {
                sentence.push_back(tolower(phrase[i]));
            }
        }

        bool fail = false;

        while(!sentence.empty()) {
            char front = sentence.front();
            char back = sentence.back();

            if(front != back) {
                fail = true;
                break;
            }

            sentence.pop_front();
            if(!sentence.empty()) sentence.pop_back();
        }

        if(!fail) {
            cout << "You won't be eaten!\n";
        } else {
            cout << "Uh oh..\n";
        }

        getline(cin,phrase);
    }

    return 0;
}
