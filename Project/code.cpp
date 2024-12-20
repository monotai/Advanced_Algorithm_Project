#include "Graph.h"
#include <cstdlib>
#include <stack>
#include <ctime>
#include <iostream>
using namespace std;

void randGraph(Graph& graph, int vertices, int MWeight) {
    int M = vertices*(vertices-1)/2;
    for(int i = 0;i < M;i++) {
        int weight = rand()%MWeight;
        int a, b;
        do {
            a = rand()%vertices;
            b = rand()%vertices;
        } while(graph.find(a,b));
        graph.addEdge(a, b, weight);
    }
}

void randpath(int vertices, Graph &graph, int maxWeight) {
    
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
    srand(time(0));
    
    int vertices = 6; // Number of vertices
    Graph graph(vertices);
    vector<int> disM(vertices), prev(vertices);
    randGraph(graph, vertices, 10);
    cout << graph.printGraph() << endl;;
    int source = 0, end = 3; // Starting vertex
    cout << "Shortest paths from vertex " << source << ":\n";
    graph.dijkstra(source, disM, prev);
    printDistanceMap(disM, source);
    printPath(prev, source, end);
    return 0;
}