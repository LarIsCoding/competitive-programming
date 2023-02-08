#include <iostream>
#include <stack>
using namespace std;
typedef long long int ll;

int main() {
    ll quant, numero, somador = 0;
    stack<int> pilha;

    cin >> quant;
    for (ll i = 0; i < quant; i++)
    {
        cin >> numero;
        if (numero != 0){
            pilha.push(numero);
            somador += pilha.top();
        }
        else {
            somador -= pilha.top();
            pilha.pop();
        }
        

    }
    cout << somador;
    
}
