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
    Graph g(m);
    g.printMatrix();
    g.printList();
}