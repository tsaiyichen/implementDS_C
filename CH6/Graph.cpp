#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

Graph::Graph(vector<vector<int>> m) {
    adjMatrix = m;
    V = m.size();
    adjList.resize(V);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++) {
            if (adjMatrix[i][j] != 0 && adjMatrix[i][j] != INF) {
                E++;
            }
        }
    }
    if(adjMatrix[0][1] == adjMatrix[1][0]){
        E /= 2;
    }
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(adjMatrix[i][j] != INF && adjMatrix[i][j] != 0){
                adjList[i].emplace_back(j, adjMatrix[i][j]);
            }
        }
    }
}

void Graph::printMatrix() {
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(adjMatrix[i][j] == INF){
                cout << setw(6) << "INF" << " ";
            }
            else{
                cout << setw(6) << adjMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void Graph::printList() {
    for(int i = 0; i < V; i++){
        cout << i << "  ->  ";
        for(auto & j : adjList[i]){
            printf("(V = %d, cost: %d), ", j.first, j.second);
        }
        cout << endl;
    }
}
