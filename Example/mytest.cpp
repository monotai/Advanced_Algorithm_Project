#include <iostream>
#include <limits.h>

using namespace std;

#define num 5
int graph[num][num];
int point[num];
 
void insert(int a, int b, int dist) {
    graph[a][b] = dist;
    graph[b][a] = dist;
}

void initialize() {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            graph[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

void initialize_point(int start) {
    for (int i = 0; i < num; i++) {
        point[i] = INT_MAX;
    }
    point[start] = 0;
}

void dijkstra(int start) {
    bool visited[num] = {false};
    for (int count = 0; count < num - 1; count++) {
        int min_dist = INT_MAX, u = -1;
        for (int i = 0; i < num; i++) {
            if (!visited[i] && point[i] <= min_dist) {
                min_dist = point[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < num; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && point[u] + graph[u][v] < point[v]) {
                point[v] = point[u] + graph[u][v];
            }
        }
    }
}

int PathReverse(int end, int* path, int index) {
    path[index] = end;
    index++;
    if (point[end] == 0) {
        return index; // Base case: reached the source node
    }

    for (int i = 0; i < num; i++) {
        // Check if there's a valid edge and the path condition is satisfied
        if (graph[i][end] != INT_MAX && point[i] == point[end] - graph[end][i]) {
            return PathReverse(i, path, index); // Recur with the next node
        }
    }

    // Return index unchanged if no valid path is found
    return index;
}

void Reverse(int* path, int size) {
    int half = size / 2;
    for (int i = 0; i < half; i++) {
        int save = path[i];
        path[i] = path[size - i - 1]; // Use size - i - 1 for correct indexing
        path[size - i - 1] = save;
    }
}

int main() {
    initialize();
    insert(0, 1, 3); // Edge from node 0 to 1 with weight 3
    insert(0, 2, 1); // Edge from node 0 to 2 with weight 1
    insert(1, 2, 7); // Edge from node 1 to 2 with weight 7
    insert(1, 3, 5); // Edge from node 1 to 3 with weight 5
    insert(2, 3, 2); // Edge from node 2 to 3 with weight 2
    insert(2, 4, 8); // Edge from node 2 to 4 with weight 8
    insert(3, 4, 4); // Edge from node 3 to 4 with weight 4

    initialize_point(0);
    dijkstra(0);
    int path[num];
    int size = PathReverse(4, path, 0);
    Reverse(path, size);

    cout << "Point : ";
    for (int i = 0; i < num; i++) {
        cout << point[i] << " ";
    }
    cout << endl;
    cout << "Path : ";
    for (int i = 0; i < size; i++) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}