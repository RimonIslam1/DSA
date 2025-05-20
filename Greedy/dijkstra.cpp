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
        cout << "Source(" << start + 1 << ") to node " << i + 1 << " cost = ";
        if (value[i] == INT_MAX)
            cout << "INF" << endl;
        else
            cout << value[i] << endl;
    }
}

int main() {
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (" << V << " x " << V << "), use 0 for no edge:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int w;
            cin >> w;
            if (i == j)
                graph[i][j] = 0;
            else if (w == 0)
                graph[i][j] = INT_MAX;
            else
                graph[i][j] = w;
        }
    }

    int start;
    cout << "Enter starting vertex (1-" << V << "): ";
    cin >> start;
    --start; // Convert to 0-based index

    dijkstra(graph, start);

    return 0;
}
