#include "Graph.h"
#include <cstdlib>
#include <stack>
#include <ctime>
#include <iostream>
using namespace std;

void randpath(int vertices, Graph &graph, int maxWeight) {
    srand(time(0));
    int u = rand() % vertices; // Random starting vertex
    int v = rand() % vertices; // Random ending vertex
    // Ensure u and v are different to avoid self-loops
    while (u == v) {
        v = rand() % vertices;
    }
    int weight = rand() % maxWeight + 1;
    graph.addEdge(u, v, weight);
    cout << "Randomly added edge: " << u << " -> " << v << " with weight " << weight << '\n';
}

void printDistanceMap(vector<int> disM, int souse) {
    if(disM.empty()) {
        cout << "No Data!\nPlease Run Dijkstra Algoritm Again!\n";
        return;
    }
    for(int i = 0;i < disM.size();i++) {
        cout << "Distand from " << souse << "to" << i << " is: " << disM[i] << '\n';
    }
}
void printPath(vector<int> prev,int source,int end) {
    if(prev.empty()) {
        cout << "No Data!\nPlease Run Dijkstra Algoritm Again!\n";
        return;
    }
    stack<int> path;
    int i = end;
    while(i != source) {
        if(i == -1) {
            cout << "No valid path exists.\n";
            return;
        }
        path.push(i);
        i = prev[i];
    }
    path.push(source);

    cout << "Path from " << source << " to " << end << ": ";
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    int vertices = 6; // Number of vertices
    Graph graph(vertices);
    vector<int> disM(vertices), prev(vertices);

    // Add edges (u, v, weight)
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(3, 4, 6);
    graph.addEdge(4, 5, 9);
    graph.addEdge(3, 5, 4);

    // Adding random edges with a maximum weight of 10
    randpath(vertices, graph, 10);
    randpath(vertices, graph, 10);

    int source = 0, end = 3; // Starting vertex
    cout << "Shortest paths from vertex " << source << ":\n";
    graph.dijkstra(source, disM, prev);
    printDistanceMap(disM, source);
    printPath(prev, source, end);
    return 0;
}