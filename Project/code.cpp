#include "Graph.h"
#include <cstdlib>
#include <stack>
#include <ctime>
#include <iostream>
using namespace std;

// Function to generate a random graph
void randGraph(Graph* graph, int vertices, int maxWeight) {
    int maxEdges = vertices * (vertices - 1) / 2;
    int Edges = rand()%maxEdges;
    for (int i = 0; i < Edges; ++i) {
        int weight = rand() % maxWeight + 1;
        int a, b;
        do {
            a = rand() % vertices;
            b = rand() % vertices;
        } while (a == b || graph->find(a, b)); // Avoid self-loops and duplicate edges
        graph->addEdge(a, b, weight);
    }
}

// Function to add a random edge
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
    srand(static_cast<unsigned>(time(0)));

    bool run = true;
    while (run) {
        Graph *graph = nullptr;
        vector<int> disM, prev;
        int vertices;
        bool hasGraph = false;
        bool findPath = false;
        cout << "\nMain Menu:\n";
        cout << "1. Generate Random Graph\n";
        cout << "2. Insert Graph Manually\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: { // Generate random graph
                cout << "Input number of vertices: ";
                cin >> vertices;
                cout << "Input max weight for edges: ";
                int maxWeight;
                cin >> maxWeight;

                graph = new Graph(vertices);
                disM.resize(vertices);
                prev.resize(vertices);
                randGraph(graph, vertices, maxWeight);
                cout << graph->printGraph() << endl;
                hasGraph = true;
                break;
            }
            case 2: { // Insert graph manually
                cout << "Input number of vertices: ";
                cin >> vertices;
                graph = new Graph(vertices);
                disM.resize(vertices);
                prev.resize(vertices);

                cout << "Input number of edges: ";
                int numEdges;
                cin >> numEdges;

                cout << "Enter edges (format: vertex1 vertex2 weight):\n";
                for (int i = 0; i < numEdges; ++i) {
                    int a, b, weight;
                    cin >> a >> b >> weight;
                    graph->addEdge(a, b, weight);
                }
                cout << graph->printGraph() << endl;
                hasGraph = true;
                break;
            }
            case 3: // Exit
                run = false;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

        while (hasGraph) {
            int source;
            cout << "\nGraph Menu:\n";
            cout << "1. Print Graph\n";
            cout << "2. Run Dijkstra's Algorithm\n";
            cout << "3. Back to Main Menu\n";
            cout << "Enter your choice: ";
            int subChoice;
            cin >> subChoice;

            switch (subChoice) {
                case 1: // Print the graph
                    cout << graph->printGraph() << endl;
                    break;
                case 2: { // Run Dijkstra's algorithm
                    cout << "Input source vertex for Dijkstra's algorithm: ";
                    cin >> source;
                    graph->dijkstra(source, disM, prev);
                    findPath = true;
                    break;
                }
                case 3: // Back to main menu
                    hasGraph = false;
                    break;

                default:
                    cout << "Invalid choice. Please try again.\n";
            }

            while (findPath) {
                int end;
                cout << "\nPath Menu:\n";
                cout << "1. Print Distance Map\n";
                cout << "2. Print Path\n";
                cout << "3. Back to Graph Menu\n";
                cout << "Enter your choice: ";
                int pathChoice;
                cin >> pathChoice;

                switch (pathChoice) {
                    case 1: // Print the distance map
                        printDistanceMap(disM, source);
                        break;
                    case 2: { // Print the path
                        cout << "Input destination vertex: ";
                        cin >> end;
                        printPath(prev, source, end);
                        break;
                    }
                    case 3: // Back to graph menu
                        findPath = false;
                        break;

                    default:
                        cout << "Invalid choice. Please try again.\n";
                }
            }
        }
        delete graph;
    }

    return 0;
}
