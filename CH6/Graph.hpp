#include <iostream>
#include <vector>
#include <list>
#define INF INT_MAX
using namespace std;

#ifndef IMPLEMENTDS_C_GRAPH_HPP
#define IMPLEMENTDS_C_GRAPH_HPP

struct triplets{
    int i;
    int j;
    int weight;
    triplets(int i, int j, int w){
        this->i = i; this->j = j; weight = w;
    }
};
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
    void Kruskal();
    void Prim(int s);
};

using namespace std;

class UnionFind {
    vector<int> parent;
public:
    UnionFind(int size) {

        parent.resize(size);

        // Initialize the parent array with each
        // element as its own representative
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    // Find the representative (root) of the
    // set that includes element i
    int find(int i) {

        // If i itself is root or representative
        if (parent[i] == i) {
            return i;
        }

        // Else recursively find the representative
        // of the parent
        return find(parent[i]);
    }
    void unite(int i, int j) {

        // Representative of set containing i
        int irep = find(i);

        // Representative of set containing j
        int jrep = find(j);

        // Make the representative of i's set
        // be the representative of j's set
        parent[irep] = jrep;
    }
};
#endif //IMPLEMENTDS_C_GRAPH_HPP
