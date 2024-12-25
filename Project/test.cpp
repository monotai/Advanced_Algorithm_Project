#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class Graph {
public:
    vector<tuple<int, int, int>> edges; // Stores edges as (vertex1, vertex2, weight)

    void addEdge(int a, int b, int weight) {
        edges.emplace_back(a, b, weight);
    }

    void printEdges() {
        for (const auto& edge : edges) {
            cout << "Edge: " << get<0>(edge) << " -> " << get<1>(edge)
                 << " with weight " << get<2>(edge) << endl;
        }
    }
};

int main() {
    cout << "Input number of edges: ";
    int numEdges;
    cin >> numEdges;

    Graph* graph = new Graph();

    cout << "Enter edges (format: vertex1 vertex2 weight):\n";
    for (int i = 0; i < numEdges; ++i) {
        int a, b, weight;
        cin >> a >> b >> weight;
        graph->addEdge(a, b, weight);
    }

    cout << "Edges in the graph:\n";
    graph->printEdges();

    delete graph; // Clean up memory
    return 0;
}
