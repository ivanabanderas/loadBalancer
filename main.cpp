#include <iostream>

#include "LoadBalancer.h"

int main()
{
    int numServers = 4;
    int maxPeticiones;

    cout << "Ingrese el número de servidores;
    cin >> numServers;

    cout << "Ingrese el número de peticiones máximas por servidor";
    cin >> maxPeticiones;

    std::vector<std::vector<int>> matrix = {
        {0, 10, 3, INF},
        {10, 0, 1, 2},
        {3, 1, 0, 8},
        {INF, 2, 8, 0}
    };

    vector <vector<int>> matrix(numServers, vector<int>(numServers, INF));

    LoadBalancer lb(numServers, matrix, maxPeticiones);

    lb.generador();

    lb.distributeRequest(0);
    lb.distributeRequest(0);
    lb.distributeRequest(1);
    lb.completeRequest(2);
    lb.distributeRequest(1);

    lb.displayServerLoads();

    return 0;
}
