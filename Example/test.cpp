#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define the structure for the graph
struct Graph {
    int vertices; // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Adjacency list (vertex, weight)

    // Constructor
    Graph(int v) : vertices(v), adjList(v) {}
    
    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // Uncomment this line for undirected graphs
    }
};

// Dijkstra's Algorithm using a priority queue
void dijkstra(const Graph& graph, int source) {
    vector<int> distances(graph.vertices, INT_MAX); // Store shortest distances
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap
    pq.emplace(0, source); // Push (distance, vertex)

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currVertex = pq.top().second;
        pq.pop();

        if (currDist > distances[currVertex]) {
            continue; // Skip if already processed with a shorter distance
        }

        for (const auto& edge : graph.adjList[currVertex]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (distances[currVertex] + weight < distances[neighbor]) {
                distances[neighbor] = distances[currVertex] + weight;
                pq.emplace(distances[neighbor], neighbor); // Push updated distance
            }
        }
    }

    // Output the shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < graph.vertices; ++i) {
        cout << i << "\t" << distances[i] << '\n';
    }
}

int main() {
    int vertices = 6; // Number of vertices
    Graph graph(vertices);

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
    dijkstra(graph, source);

    return 0;
}
