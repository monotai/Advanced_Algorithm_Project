#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<pair<int,int>>>& adj, int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void displayAdjList(vector<vector<pair<int,int>>>& adj) {
    for(int i = 0;i < adj.size();i++) {
        cout << i << ": ";
        for(auto &j : adj[i]) {
            cout << "{" << j.first << "," << j.second << "} ";
        }
        cout << endl;
    }
}

int main() {
  
    // Create a graph with 3 vertices and 3 edges
    int V = 3;
    vector<vector<pair<int,int>>> adj(V); 

    // Now add edges one by one
    addEdge(adj, 1, 0, 3);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 0, 1);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);

    return 0;
}