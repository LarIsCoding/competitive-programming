#include <iostream>
#include <iomanip>

using namespace std;

double calculateConsumption(double dist, double lastDist, double consumption, double leak) {
    return (dist - lastDist) * (leak + consumption / (double)100) ;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    double lastDist, dist, consumption;
    string type;

    cin >> lastDist >> type >> type >> consumption;

    while(consumption > 0) {
        double total = 0;
        double maior = 0;
        double leak = 0;

        cin >> dist >> type;

        while(type != "Goal") {
            
            total += calculateConsumption(dist, lastDist, consumption, leak);

            if(type == "Fuel") {
                cin >> type;
                cin >> consumption;

            } else if(type == "Leak") {
                leak++;

            } else if(type == "Mechanic") {
                leak = 0;

            } else if(type == "Gas") {
                cin >> type;
                maior = max(maior, total);
                total = 0;
            }
            lastDist = dist;
            cin >> dist >> type;
        }

        total += calculateConsumption(dist, lastDist, consumption, leak);
        maior = max(maior, total);

        cout << setprecision(3) << fixed << maior << endl;

        cin >> lastDist >> type >> type >> consumption;
    }

    return 0;
}
