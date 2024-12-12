#include "Graph.h"

int main() {
    Graph g(3); // Create a graph with 3 vertices.

    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    cout << "Initial Adjacency List:" << endl;
    g.displayAdjList();

    g.addVertices(2); // Add 2 more vertices to the graph.
    g.addEdge(3, 4, 30); // Add an edge between the new vertices.
    g.addEdge(2, 3, 40); // Connect existing and new vertices.

    cout << "Updated Adjacency List after adding vertices:" << endl;
    g.displayAdjList();

    return 0;
}
