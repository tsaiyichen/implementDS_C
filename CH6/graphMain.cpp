#include <iostream>
#include "Graph.hpp"
#define INF INT_MAX
using namespace std;

int main(){
    vector<vector<int>> m = {{0, 16, INF, INF, 19, 21},
                             {16, 0, 5, 6, INF, 11},
                             {INF, 5, 0, 10, INF, INF},
                             {INF, 6, 10, 0, 18, 14},
                             {19, INF, INF, 18, 0, 33},
                             {21, 11, INF, 14, 33, 0}};
    vector<vector<int>> m2 = {{0, INF, INF, INF, INF, INF, INF, INF},
                              {300, 0, INF, INF, INF, INF, INF, INF},
                              {1000, 800, 0, INF, INF, INF, INF, INF},
                              {INF, INF, 1200, 0, INF, INF, INF, INF},
                              {INF, INF, INF, 1500, 0, 250, INF, INF},
                              {INF, INF, INF, 1000, INF, 0, 900, 1400},
                              {INF, INF, INF, INF, INF, INF, 0, 1000},
                              {1700, INF, INF, INF, INF, INF, INF, 0}};
    vector<vector<int>> m3 = {{0, 4, 11}, {6, 0, 2}, {3, INF, 0}};
    Graph g(m);
    Graph g2(m2);
    Graph g3(m3);
    g.printMatrix();
    g.printList();
    cout << "DFS_recursive: " << endl;
    g.DFS_recursive(0);
    cout << endl << "DFS_stack: " << endl;
    g.DFS_stack(0);
    cout << endl << "BFS: " << endl;
    g.BFS(0);
    cout << endl << "Kruskal: " << endl;
    g.Kruskal();
    cout << endl << "Prim's: " << endl;
    g.Prim(0);
    cout << endl << "Dijkstra: " << endl;
    g2.printMatrix();
    g2.Dijkstra(4);
    cout << endl << "BellmanFord: " << endl;
    g2.BellmanFord(4);
    cout << endl << "FloydWarshall: " << endl;
    g3.FloydWarshall();
}