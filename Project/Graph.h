#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

using namespace std;
//undirected graph
class Graph{
    private:
    vector<vector<pair<int,int>>> graph;
    public:
    Graph(int vertices) {
        graph.resize(vertices);
    }

    void addVertices(int count) {
        if (count <= 0) {
            cout << "Error: The number of vertices to add must be positive." << endl;
            return;
        }
        graph.resize(graph.size() + count);
        cout << count << " vertices added. New total: " << graph.size() << " vertices." << endl;
    }

    void addEdge(int u, int v, int w) {
        if (u >= graph.size() || v >= graph.size()) {
            cout << "Error: Vertex index out of bounds!" << endl;
            return;
        }
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        
    }

    void displayAdjList() {
        for (int i = 0; i < graph.size(); i++) {
            cout << i << ": "; 
            for (auto &j : graph[i]) {
                cout << "{"<<j.first << ", "<<j.second<<"} "; 
            }
            cout << endl; 
        }
    }

    int getVertexCount() const {
        return graph.size();
    }

    void dijkstra(int start) {
        vector<int> priorityQueue;
        
    }
};
#endif