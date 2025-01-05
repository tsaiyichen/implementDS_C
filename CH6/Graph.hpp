#include <iostream>
#include <vector>
#include <list>
#define INF INT_MAX
using namespace std;

#ifndef IMPLEMENTDS_C_GRAPH_HPP
#define IMPLEMENTDS_C_GRAPH_HPP


class Graph {
private:
    vector<vector<int>> adjMatrix; //costMatrix
    int V; //number of vertices
    vector<list<pair<int, int>>> adjList; //pair(vertices no, cost)
    int E = 0; //number of edges
    vector<bool> visited;
public:
    explicit Graph(vector<vector<int>> m);
    void printMatrix();
    void printList();
    void DFS_recursive(int start);
    void flush();
    void DFS_stack(int start);
    void BFS(int start);
};


#endif //IMPLEMENTDS_C_GRAPH_HPP
