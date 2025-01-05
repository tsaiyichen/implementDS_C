#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;

Graph::Graph(vector<vector<int>> m) {
    adjMatrix = m;
    V = m.size();
    visited.resize(V);
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

void Graph::DFS_recursive(int start) {

    printf("%d, ", start);
    visited[start] = true;
    for(int i = 0; i < V; i++){
        if(adjMatrix[start][i] != 0 && adjMatrix[start][i] != INF && visited[i] == false){
            DFS_recursive(i);
        }
    }

}

void Graph::DFS_stack(int start) {
    flush();
    stack<int> stack;
    stack.push(start);
    /*
    while(!stack.empty()){
        int v = stack.top();
        stack.pop();
        if(visited[v]){
            continue;
        }
        printf("%d, ", v);
        visited[v] = true;
        for(int i = V - 1; i >= 0; i--){
            if(adjMatrix[v][i] != 0 && adjMatrix[v][i] != INF && visited[i] == false){
                stack.push(i);
            }
        }
    }
    */
    while(!stack.empty()){
        int v = stack.top();
        stack.pop();
        if(visited[v]){
            continue;
        }
        printf("%d, ", v);
        visited[v] = true;
        for(auto &i: adjList[v]){
            if(!visited[i.first]){
                stack.push(i.first);
            }
        }
    }
}

void Graph::BFS(int start) {
    flush();
    queue<int> queue;
    queue.push(start);
    /*
    while(!queue.empty()){
        int v = queue.front();
        queue.pop();
        if(visited[v]){
            continue;
        }
        printf("%d, ", v);
        visited[v] = true;
        for(int i = 0; i < V; i++){
            if(adjMatrix[v][i] != 0 && adjMatrix[v][i] != INF && visited[i] == false){
                queue.push(i);
            }
        }
    }
    */
    while(!queue.empty()){
        int v = queue.front();
        queue.pop();
        if(visited[v]){
            continue;
        }
        printf("%d, ", v);
        visited[v] = true;
        for(auto &i: adjList[v]){
            if(!visited[i.first]){
                queue.push(i.first);
            }
        }
    }

}

void Graph::flush() {
    fill(visited.begin(), visited.end(), false);
}
