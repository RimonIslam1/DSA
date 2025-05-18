#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

const int INF = INT_MAX;

vector<int> print_path(const vector<int>& parent, int v) {
    if (v == -1) {
        return {};
    }
    vector<int> path = print_path(parent, parent[v]);
    path.push_back(v + 1); // Convert to 1-based indexing
    return path;
}

void bellman_ford(const vector<vector<int>>& edges, int V) {
    vector<int> parent(V, -1);
    vector<int> dist(V, INF);
    dist[0] = 0; // Start from vertex 0 (which is vertex 1 for the user)

    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != INF && dist[v] > w + dist[u]) {
                dist[v] = w + dist[u];
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        if (dist[i] == INF) {
            cout << "There is no path from 1 to " << i + 1 << endl;
        } else {
            cout << "Cost from 1 to " << i + 1 << " = " << dist[i] << endl;
            vector<int> path = print_path(parent, i);
            cout << "Path: ";
            for (size_t j = 0; j < path.size(); ++j) {
                if (j != 0) cout << " -> ";
                cout << path[j];
            }
            cout << "\n\n";
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of Vertices and Edges: ";
    cin >> V >> E;
    
    vector<vector<int>> edges;
    cout << "Enter " << E << " edges in the format: src dst wt" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u - 1, v - 1, w}); // Convert to 0-based indexing
    }

    bellman_ford(edges, V);
    
    return 0;
}