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
    int maxPeticiones; //número máximo de peticiones
    std::vector<std::vector<int>> adjMatrix;
    std::vector<int> requestsPerServer;

public:
    LoadBalancer(int n, const std::vector<std::vector<int>>& matrix, int maxPeticiones);
    int distributeRequest(int startServer);
    void completeRequest(int serverId);
    void displayServerLoads();
    int servidorLleno(int serverID);  //revisar si el servidor esta lleno
    void generador();  //generar los costos de forma aleatoria
};

#endif
