#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);

    long long quant, H, atual, proximo, anterior;
    cin >> quant;
    vector<long long> vetor; 

    if (quant == 1)
    {
        cout << "Yes";
    }
    else
    {
        for (long long i = 0; i < quant; i++)
    {
        cin >> H;
        vetor.push_back(H);
    }
    
    for (long long i = 0; i < quant; i++){

        atual = vetor[i];

        /* Primeiro */
        if (i == 0)
        {
            proximo = vetor[i + 1];

            if (atual > proximo)
            {
                if (atual - 1 <= proximo)
                {
                    vetor[i] = vetor[i] - 1;
                }
                else
                {
                    cout << "No";
                    break;
                }
            }
            else
            {
                continue;
            }
            
        }

        /* Último */
        else if (i == quant - 1)
        {
            cout << "Yes";
        }

        /* Meio */
        else
        {
            proximo = vetor[i+1];
            if (atual > proximo)
            {
                anterior = vetor[i -1];

                if (atual - 1 < anterior)
                {
                    cout << "No";
                    break;
                }
                else
                {
                    if (atual - 1 <= proximo){
                        vetor[i] = vetor[i] - 1;
                    }
                    else
                    {
                        cout << "No";
                        break;
                    }
                    
                    
                }
            }
            else
            {
                continue;
            }
        }
    }
    }
     
    return 0;
}
