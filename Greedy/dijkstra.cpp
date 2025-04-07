#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int V = 8; // Number of vertices

int select_min_vertex(vector<int>& value, vector<bool>& processed) {
    int minimum = INT_MAX;
    int vertex = -1;

    for (int i = 0; i < V; ++i) {
        if (!processed[i] && value[i] < minimum) {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void dijkstra(vector<vector<int>>& graph, int start) {
    vector<int> parent(V, -1);               // Stores shortest path structure
    vector<int> value(V, INT_MAX);           // Shortest path estimate
    vector<bool> processed(V, false);        // Track processed vertices

    value[start] = 0; // Distance from start to itself is 0

    for (int i = 0; i < V - 1; ++i) {
        int U = select_min_vertex(value, processed);
        if (U == -1) break;
        processed[U] = true;

        for (int j = 0; j < V; ++j) {
            if (graph[U][j] != INT_MAX && !processed[j] &&
                value[U] + graph[U][j] < value[j]) {
                value[j] = value[U] + graph[U][j];
                parent[j] = U;
            }
        }
    }

    // Output shortest path results
    for (int i = 0; i < V; ++i) {
        cout << "Source(" << start + 1 << ") to node " << i + 1 << " cost = " << value[i] << endl;
    }
}

int main() {
    // Initialize graph with INT_MAX to represent infinity
    vector<vector<int>> graph(V, vector<int>(V, INT_MAX));

    // Define edges and weights (just like the Python version)
    graph[0][0] = 0;
    graph[1][0] = 300; graph[1][1] = 0;
    graph[2][0] = 1000; graph[2][1] = 800; graph[2][2] = 0;
    graph[3][2] = 1200; graph[3][3] = 0;
    graph[4][3] = 1500; graph[4][4] = 0; graph[4][5] = 250;
    graph[5][3] = 1000; graph[5][5] = 0; graph[5][6] = 900; graph[5][7] = 1400;
    graph[6][6] = 0; graph[6][7] = 1000;
    graph[7][0] = 1700; graph[7][7] = 0;

    int start = 4; // Starting vertex (index 4 means node 5)
    dijkstra(graph, start);

    return 0;
}
