#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void allPairShortestPath(const vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;
                if (dist[i][i] < 0) {
                    cout << "Negative weight cycle detected." << endl;
                    return;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Output the result
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << (i + 1) << " -> " << (j + 1) << " = ";
            if (dist[i][j] == INF)
                cout << "INF";
            else
                cout << dist[i][j];
            cout << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, INF, 7},
        {INF, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    allPairShortestPath(graph);

    return 0;
}
