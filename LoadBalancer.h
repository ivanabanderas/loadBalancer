#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

const int INF = INT_MAX;

class LoadBalancer {
private:
    int numServers;
    int maxPeticiones;
    std::vector<std::vector<int>> adjMatrix;
    std::vector<int> requestsPerServer;

public:
    LoadBalancer(int n, const std::vector<std::vector<int>>& matrix);
    int distributeRequest(int startServer);
    void completeRequest(int serverId);
    void displayServerLoads();
    int servidorLleno();
    void generador();
};

#endif
