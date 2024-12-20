#include <iostream>
#include <stack>
#include "Graph.h"

using namespace std;
// Function to generate a random graph
void randGraph(Graph* graph, int vertices, int maxWeight) {
    int maxEdges = vertices * (vertices - 1) / 2;
    for (int i = 0; i < maxEdges; ++i) {
        int weight = rand() % maxWeight + 1;
        int a, b;
        do {
            a = rand() % vertices;
            b = rand() % vertices;
        } while (a == b || graph->find(a, b)); // Avoid self-loops and duplicate edges
        graph->addEdge(a, b, weight);
    }
}
void randpath(Graph* graph,int vertices, int vertex, int maxWeight) {
    int v = rand() % vertices;
    while (vertex == v || graph->find(vertex, v)) {
        v = rand() % vertices;
    }
    int weight = rand() % maxWeight + 1;
    graph->addEdge(vertex, v, weight);
    cout << "Randomly added edge: " << vertex << " -> " << v << " with weight " << weight << '\n';
}

// Function to print the distance map
void printDistanceMap(const vector<int>& disM, int source) {
    if (disM.empty()) {
        cout << "No data! Please run Dijkstra's algorithm again.\n";
        return;
    }
    for (size_t i = 0; i < disM.size(); ++i) {
        cout << "Distance from " << source << " to " << i << " is: " << disM[i] << '\n';
    }
}

// Function to print the path from source to destination
void printPath(const vector<int>& prev, int source, int end) {
    if (prev.empty()) {
        cout << "No data! Please run Dijkstra's algorithm again.\n";
        return;
    }
    stack<int> path;
    int current = end;
    while (current != source) {
        if (current == -1) {
            cout << "No valid path exists.\n";
            return;
        }
        path.push(current);
        current = prev[current];
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
    Graph *graph = nullptr;
    vector<int> disM(5), prev(5);
    graph = new Graph(5);
    randGraph(graph, 5, 10);
    cout << graph->printGraph() << endl;
    graph->dijkstra(0, disM, prev);
    printDistanceMap(disM, 0);
    printPath(prev, 0, 4);
    delete graph;
    return 0;
}