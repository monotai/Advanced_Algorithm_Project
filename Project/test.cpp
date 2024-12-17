#include "Graph.h"

int main() {
    int vertices = 6; // Number of vertices
    Graph graph(vertices);
    int distM[vertices], prev[vertices];

    // Add edges (u, v, weight)
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(3, 4, 6);
    graph.addEdge(4, 5, 9);
    graph.addEdge(3, 5, 4);

    int source = 0; // Starting vertex
    cout << "Shortest paths from vertex " << source << ":\n";
    graph.dijkstra(source, distM, prev);
    return 0;
}
