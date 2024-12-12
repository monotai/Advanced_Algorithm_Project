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
    vector<int> distanceMap;

    Graph(int v) : vertices(v), adjList(v) , distanceMap(v){}
    
    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    void dijkstra(int source) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> priorityQueue;
        vector<int> predecessor(vertices);

        distanceMap[source] = 0;
        priorityQueue.push({source, 0});

        for(int i = 0;i < vertices;i++) {
            if(i != source) {
                predecessor[i] = -1;
                distanceMap[i] = INT_MAX;
                priorityQueue.push({i, INT_MAX});
            }
        }

        while(!priorityQueue.empty()) {
            int vertex = priorityQueue.top().first;
            int distance = priorityQueue.top().second;
            priorityQueue.pop();

            for(auto& nieghbor : adjList[vertex]) {
                int vertexNieghbor = nieghbor.first;
                int alt = distanceMap[vertex] + nieghbor.second;
                if(alt < distanceMap[vertexNieghbor]) {
                    predecessor[vertexNieghbor] = vertex;
                    distanceMap[vertexNieghbor] = alt;
                    priorityQueue.push({vertexNieghbor, alt});
                }
            }
        }
        for (int i = 0; i < vertices; ++i) {
        cout << "Vertex " << i << ": Distance = " << distanceMap[i];
        if (predecessor[i] != -1)
            cout << ", Previous Vertex = " << predecessor[i];
        cout << endl;
        }
    }
};

#endif
