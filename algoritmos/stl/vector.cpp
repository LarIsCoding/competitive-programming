#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Retorna true se o primeiro argumento deve vir antes do segundo na ordenação fraca estrita
// Diz se a é "menor que" b
bool compare(int a, int b) {
    return a < b;
}

int main() {
    vector<int> v;

    v.reserve(10); // melhora a performance

    v.push_back(7);
    v.assign(5, 2); // assign(size, value)
    v.erase(v.begin()); // erase(it), erase(begin, end)

    cout << v.at(0) << endl; // 2
    cout << v[0] << endl; // 2
    cout << v.size() << endl; // 4

    sort(v.begin(), v.end(), greater<int>()); // ordena em ordem decrescente
    sort(v.rbegin(), v.rend()); // ordena em ordem decrescente
    stable_sort(v.begin(), v.end(), compare); // mantem a ordem relativa entre elementos de valor equivalente

    lower_bound(v.begin(), v.end(), 5); // retorna o primeiro elemento que não é menor que 5
    upper_bound(v.begin(), v.end(), 5, compare); // retorna o primeiro elemento que é maior do que 5
    binary_search(v.begin(), v.end(), 5); // retorna true se 5 está no vetor

    v.clear(); // limpa vetor

    return 0;
}