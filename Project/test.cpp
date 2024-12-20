// Function to add a random edge
void randpath(Graph& graph,int vertices, int vertex, int maxWeight) {
    int v = rand() % vertices;
    while (vertex == v || graph.find(vertex, v)) {
        v = rand() % vertices;
    }
    int weight = rand() % maxWeight + 1;
    graph.addEdge(vertex, v, weight);
    cout << "Randomly added edge: " << vertex << " -> " << v << " with weight " << weight << '\n';
}