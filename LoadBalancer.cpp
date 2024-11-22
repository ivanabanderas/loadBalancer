#include "LoadBalancer.h"

using namespace std;

int fullServers = 0;

LoadBalancer::LoadBalancer(int n, const std::vector<std::vector<int>>& matrix, int maxRequests)
: numServers(n), adjMatrix(matrix), requestsPerServer(n, 0), maxRequests(maxRequests){};


int LoadBalancer::distributeRequest(int startServer) {
    int minCost = INF;
    int selectedServer = -1 ;

    for (int i = 0; i < numServers; ++i) {
        if (i != startServer && adjMatrix[startServer][i] != INF) {
            // Se valida si los request activos del servidor seleccionado son menores que
            // los que estan activos en la iteracion de la matrix o si el servidor seleccionado
            // no se ha asignado
            if ((requestsPerServer[i] < maxRequests) && (requestsPerServer[i] < requestsPerServer[selectedServer] || selectedServer == -1) &&
                (adjMatrix[startServer][i] < minCost)) {
                // se actualiza el costo del servidor ese costo se encuentra el la matrix
                minCost = adjMatrix[startServer][i];
                selectedServer = i;
                }
        }
    }

    if (selectedServer != -1) {
        requestsPerServer[selectedServer]++;
        cout << "Solicitud asignada al Servidor " << selectedServer
                  << " desde Servidor " << startServer << ", Carga actual: "
                  << requestsPerServer[selectedServer] << "\n";
    } 
    else if(fullServers == numServers -1){
        cout << "Todos los servidores estan llenos \n";
    }
    else {
        cout << "No hay servidores disponibles desde el Servidor " << startServer << "\n";
    }
    return selectedServer;

}

void LoadBalancer::completeRequest(int serverId) {
    // Se valida que el servidor exista y que exista dentro de los servidores inicializados
    // o que el servidor tenga al menos 1 solicitud
    if(serverId < 0 || serverId >= numServers || requestsPerServer[serverId] == 0) {
        cout << "Error: no hay solicitudes activas en el Servidor " << serverId << "\n";
        return;
    }

    requestsPerServer[serverId]--;
    std::cout << "Solicitud completada en el Servidor " << serverId
             << ", Carga actual: " << requestsPerServer[serverId] << "\n";
}

void LoadBalancer::displayServerLoads() {
    std::cout << "Cargas actuales de los servidores:\n";
    for (int i = 0; i < numServers; ++i) {
        std::cout << "Servidor " << i << ": " << requestsPerServer[i] << " solicitudes\n";
    }
}
