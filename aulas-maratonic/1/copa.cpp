#include <iostream>
#include <queue>
using namespace std;

int main() {

   ios::sync_with_stdio(false);
   cin.tie(0);

   int gol_a, gol_b;
   char a, b;
   queue<char> competidores;

   for(char c = 'A'; c < 'Q'; c++) {
       competidores.push(c);
   }

   for(int i = 0; i < 15; i++) {
       a = competidores.front();
       competidores.pop();

       b = competidores.front();
       competidores.pop();

       cin >> gol_a >> gol_b;

       if (gol_a >= gol_b) {
           competidores.push(a);
       } else {
           competidores.push(b);
       }
   }

   cout << competidores.front() << '\n';

   return 0;
}
