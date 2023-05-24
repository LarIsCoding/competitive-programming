#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> mapper;

    mapper["john"] = 78;
    mapper["billy"] = 69;
    mapper["lare"] = 50;

    cout << mapper["john"] << endl;

    for(map<string, int>::iterator it = mapper.lower_bound("f"); it != mapper.upper_bound("m"); it++) {
        cout << it->first << endl;
        cout << it->second << endl;
    }

    mapper.clear();

    return 0;
}