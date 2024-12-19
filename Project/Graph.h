#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "./PriorityQueue.h"

using namespace std;

//for set second element is priority
class Compare{
    public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

class Graph {
    public:
    int vertices;
    vector<vector<pair<int, int>>> adjList;
    

    Graph(int v) : vertices(v), adjList(v) {}
    
    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    void dijkstra(int source, vector<int>& distM,  vector<int>& prev) {
        PriorityQueue pQ;

        distM[source] = 0;
        prev[source] = source;
        pQ.add_with_priority(source, 0);

        for(int v = 0;v < vertices;v++) {
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
};

#endif
