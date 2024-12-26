#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "./PriorityQueue.h"

using namespace std;

class Graph {
    public:
    vector<vector<pair<int, int>>> adjList;
    

    Graph(int v) : adjList(v) {}

    void addVertices(int vertex) {
        int oldsize = adjList.size();
        adjList.resize(oldsize + vertex);
        if(adjList.size()-vertex < oldsize) {
            cout << "Error: Could not add vertices\n";
        }
    }

    void addEdge(int u, int v, int weight) {
        if(find(u, v)) {
            return;
        }
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    void dijkstra(int source, vector<int>& distM,  vector<int>& prev) {
        PriorityQueue pQ;

        distM[source] = 0;
        prev[source] = source;
        pQ.add_with_priority(source, 0);

        for(int v = 0;v < adjList.size();v++) {
            if(v != source) {
                prev[v] = -1;
                distM[v] = INT_MAX;
                pQ.add_with_priority(v, INT_MAX);
            }
        }
        
        while(pQ.head != nullptr) {
            int u = pQ.extract_min();
            for(auto& n : adjList[u]) {
                int v = n.first;
                int alt = distM[u] + n.second;
                if(alt < distM[v]) {
                    prev[v] = u;
                    distM[v] = alt;
                    pQ.decrease_priority(v, alt);
                }
            }
        }
        
    }
    bool find(int a, int b) {
        for(auto v : adjList[a]) {
            if(v.first == b) {
                return true;
            }
        }
        return false;
    }
    string printGraph() {
        string result;
        for (int i = 0; i < adjList.size(); ++i) {
            result += to_string(i) + ": ";
            for (auto& neighbor : adjList[i]) {
                result += "(" + to_string(neighbor.first) + ", " + to_string(neighbor.second) + ") ";
            }
            result += "\n";
        }
        return result;
    }
    int size() {
        return adjList.size();
    }
};

#endif
