    #include <iostream>

    #include "LoadBalancer.h"

    int main(){
        srand(time(nullptr));   // para poder generar los números aleatorios

        int numServers;
        cout << "Cuantos servidores quiere configurar? \n";
        cin >> numServers;

        int maxRequests;
        cout << "Cual es el limite maximo de peticiones por servidor? \n";
        cin >> maxRequests;

        vector<vector<int>> matrix(numServers, vector<int>(numServers, INF)); //se inializa el vector para poder crear la matriz


        //Matriz de adyacencia, para el número de servidores con los números generados
        for(int i = 0; i< numServers; ++i){
            for(int j = 0; j < numServers; j++){
                if (i == j){
                    matrix[i][j] = 0;    //en el caso que sea el mismo servior se pone 0
                }
                else{
                    int cost = (rand() % 100 < 80) ? rand() % 10 + 1 : INF;
                    matrix[i][j] = cost;     //se crea el costo aleatorio
                    matrix[i][j] = cost;     //se crea el costo aleatorio
                }
            }
        }

        //Imprimir la matriz
        cout << "Matriz: \n";
        for(int i = 0; i< numServers; ++i){
            for(int j = 0; j < numServers; j++){
                if (matrix[i][j] == INF){
                cout << "INF\t";
                }
                else{
                    cout << matrix[i][j] << "\t";
                }
            }
            cout << "\n";
        }

        LoadBalancer lb(numServers, matrix, maxRequests);

        lb.distributeRequest(0);
        lb.distributeRequest(0);
        lb.distributeRequest(1);
        lb.completeRequest(2);
        lb.distributeRequest(1);

        lb.displayServerLoads();

        return 0;
    }

//video: https://drive.google.com/drive/folders/1prhZdpXMNeJnauPBtPP9NQGFsmySgysO?usp=sharing
