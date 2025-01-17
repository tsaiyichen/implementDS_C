#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
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

void Graph::Kruskal() {

    if(adjMatrix[0][1] != adjMatrix[1][0]) return;
    vector<tuple<int, int, int>> edgeVector;
    /*
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    for(int i = 0; i < V; i++){
        for(int j = i + 1; j < V; j++){
            if(adjMatrix[i][j] != 0 && adjMatrix[i][j] != INF)
            edgeVector.emplace_back(adjMatrix[i][j], i, j);
        }
    }

    for(auto & i : edgeVector){
        pq.emplace(i);
    }
    UnionFind set(V);
    int count = 0;
    while(!pq.empty() && count < V - 1){
        auto [w, i, j] = pq.top();
        pq.pop();
        //check cycle
        if(set.find(i) != set.find(j)){
            //no cycle
            set.unite(i, j); //union
            printf("%d -> %d, weight: %d\n", i, j, w);
            count++;
        }else{
            //discard this edge
        }
    }
    */
    for(int i = 0; i < V; i++){
        for(auto &j: adjList[i]){
            if(i >= j.first){
                continue;
            }
            edgeVector.emplace_back(j.second, i, j.first);
        }
    }
    sort(edgeVector.begin(), edgeVector.end(), [](const auto& a, const auto& b) {
        return get<0>(a) < get<0>(b);
    });
    UnionFind set(V);
    int count = 0;
    for(int i = 0; i < edgeVector.size(); i++){
        auto [w, k, j] = edgeVector[i];
        if(set.find(k) != set.find(j)){
            //no cycle
            set.unite(k, j); //union
            printf("%d -> %d, weight: %d\n", k, j, w);
            count++;
        }else{
            //discard edge
        }
        if(count > V - 1){
            break;
        }
    }
}

void Graph::Prim(int s) {
    if(adjMatrix[0][1] != adjMatrix[1][0]) return;
    /*
    set<int> x, y; // x: U, y: V - U
    x.emplace(s); // U
    for(int i = 0; i < V; i++){
        if(i != s) y.emplace(i);
    }

    while(!y.empty()){
        int start = -1, end = -1, minWeight = INF;
        for(int i = 0; i < V; i++){
            if(x.find(i) != x.end()){
                for(int j = 0; j < V; j++){
                    if(y.find(j) != y.end() && adjMatrix[i][j] != INF && adjMatrix[i][j] != 0){
                        if(adjMatrix[i][j] < minWeight){
                            minWeight = adjMatrix[i][j];
                            start = i;
                            end = j;
                        }
                    }
                }
            }
        }

        printf("%d -> %d, weight: %d\n", start, end, minWeight);
        x.emplace(end);
        y.erase(end);
    }
    */
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    //initialize
    for(int i = 0; i < V; i++){
        if(i != s){
            pq.emplace(INF, i, -1);
        }else{
            pq.emplace(0, s, -1);
        }
    }
    while(!pq.empty()){
        auto [weight, no, p] = pq.top();
        pq.pop();
        if(p != -1){
            printf("%d -> %d, weight: %d\n", p, no, weight);
        }
        for(auto &i: adjList[no]){
            auto cur = i.first;
            vector<tuple<int, int, int>> temp;
            while(!pq.empty()){
                auto [c, a, b] = pq.top();
                pq.pop();
                if(a == cur && c > i.second){
                    pq.emplace(i.second, i.first, no);
                }else{
                    temp.emplace_back(c, a, b);
                }
            }
            for(auto &j: temp){
                pq.emplace(j);
            }
            temp.clear();
        }
    }

}
