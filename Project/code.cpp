#include "Graph.h"
#include <cstdlib>
#include <stack>
#include <ctime>
#include <iostream>
using namespace std;

// Function to generate a random graph
void randGraph(Graph& graph, int vertices, int maxWeight) {
    int maxEdges = vertices * (vertices - 1) / 2;
    for (int i = 0; i < maxEdges; ++i) {
        int weight = rand() % maxWeight + 1;
        int a, b;
        do {
            a = rand() % vertices;
            b = rand() % vertices;
        } while (a == b || graph.find(a, b)); // Avoid self-loops and duplicate edges
        graph.addEdge(a, b, weight);
    }
}

// Function to add a random edge
void randpath(int vertices, Graph& graph, int maxWeight) {
    int u = rand() % vertices;
    int v = rand() % vertices;
    while (u == v || graph.find(u, v)) {
        v = rand() % vertices;
    }
    int weight = rand() % maxWeight + 1;
    graph.addEdge(u, v, weight);
    cout << "Randomly added edge: " << u << " -> " << v << " with weight " << weight << '\n';
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
    srand(static_cast<unsigned>(time(0)));

    int vertices = 6; // Default number of vertices
    Graph graph(vertices);
    vector<int> disM(vertices), prev(vertices);

    randGraph(graph, vertices, 10);
    cout << graph.printGraph() << endl;

    int source = 0, end = 3; // Default source and destination vertices
    graph.dijkstra(source, disM, prev);
    printDistanceMap(disM, source);
    printPath(prev, source, end);

    bool run = true;
    while (run) {
        cout << "\nMenu:\n";
        cout << "1. Generate Random Graph\n";
        cout << "2. Insert Graph Manually\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Input number of vertices: ";
                cin >> vertices;
                cout << "Input max weight for edges: ";
                int maxWeight;
                cin >> maxWeight;

                graph = Graph(vertices);
                randGraph(graph, vertices, maxWeight);
                cout << graph.printGraph() << endl;

                cout << "Input source vertex for Dijkstra's algorithm: ";
                cin >> source;
                graph.dijkstra(source, disM, prev);
                printDistanceMap(disM, source);
                break;
            }
            case 2: {
                cout << "Input number of vertices: ";
                cin >> vertices;
                graph = Graph(vertices);

                cout << "Input number of edges: ";
                int numEdges;
                cin >> numEdges;

                cout << "Enter edges (format: vertex1 vertex2 weight):\n";
                for (int i = 0; i < numEdges; ++i) {
                    int a, b, weight;
                    cin >> a >> b >> weight;
                    graph.addEdge(a, b, weight);
                }
                cout << graph.printGraph() << endl;

                cout << "Input source vertex for Dijkstra's algorithm: ";
                cin >> source;
                graph.dijkstra(source, disM, prev);
                printDistanceMap(disM, source);
                break;
            }
            case 3:
                run = false;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

        if (run) {
            cout << "\nDo you want to add a random edge? (y/n): ";
            char c;
            cin >> c;
            if (c == 'y') {
                randpath(vertices, graph, 10);
                cout << graph.printGraph() << endl;
            }
        }
    }

    return 0;
}
