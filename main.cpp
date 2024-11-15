#include <iostream>

#include "LoadBalancer.h"

int main()
{
    int numServers = 4;

    std::vector<std::vector<int>> matrix = {
        {0, 10, 3, INF},
        {10, 0, 1, 2},
        {3, 1, 0, 8},
        {INF, 2, 8, 0}
    };

    LoadBalancer lb(numServers, matrix);

    lb.distributeRequest(0);
    lb.distributeRequest(0);
    lb.distributeRequest(1);
    lb.completeRequest(2);
    lb.distributeRequest(1);

    lb.displayServerLoads();

    return 0;
}
