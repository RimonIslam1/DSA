#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int find_min_vertex(int V, vector<int>& value, vector<bool>& visited) {
    int minVal = INT_MAX;
    int vertex = -1;

    for (int i = 0; i < V; ++i) {
        if (!visited[i] && value[i] < minVal) {
            vertex = i;
            minVal = value[i];
        }
    }

    return vertex;
}

vector<int> prims_algo(vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1);         // Stores MST
    vector<int> value(V, INT_MAX);     // Min weights to add vertices
    vector<bool> visited(V, false);    // Marks if vertex is in MST

    value[0] = 0;  // Start from vertex 0

    for (int i = 0; i < V - 1; ++i) {
        int u = find_min_vertex(V, value, visited);
        visited[u] = true;

        for (int j = 0; j < V; ++j) {
            if (graph[u][j] != 0 && !visited[j] && graph[u][j] < value[j]) {
                value[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    return parent;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    /*
    vector<vector<int>> graph = {
        {0, 11, 13, 0, 2, 0, 0, 0},
        {11, 0, 15, 8, 12, 0, 6, 0},
        {13, 15, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 0, 14, 0, 10, 17},
        {2, 12, 0, 14, 0, 5, 0, 0},
        {0, 0, 0, 0, 5, 0, 0, 7},
        {0, 6, 0, 10, 0, 0, 0, 21},
        {0, 0, 0, 17, 0, 7, 21, 0}
    };
    */

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (enter 0 if no edge):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<int> mst = prims_algo(graph, V);

    int total_cost = 0;

    for (int i = 1; i < V; ++i) {
        cout << "Path: " << mst[i] + 1 << " -> " << i + 1
             << " : cost = " << graph[i][mst[i]] << endl;
        total_cost += graph[i][mst[i]];
    }

    cout << "Total Cost = " << total_cost << endl;

    return 0;
}
