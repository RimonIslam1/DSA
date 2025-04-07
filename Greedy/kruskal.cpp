#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
    vector<int> parent;

public:
    DSU(int n) {
        parent.resize(n + 1, -1); // For 1-based indexing
    }

    int find_absolute_parent(int v) {
        if (parent[v] == -1) {
            return v;
        }
        return parent[v] = find_absolute_parent(parent[v]); // Path compression
    }

    void union_operation(int from_v, int to_v) {
        int from_p = find_absolute_parent(from_v);
        int to_p = find_absolute_parent(to_v);
        if (from_p != to_p) {
            parent[from_p] = to_p; // No union by rank
        }
    }
};

vector<vector<int>> kruskal(vector<vector<int>>& edge_list, int tot_v) {
    // Sort the edges based on weight
    sort(edge_list.begin(), edge_list.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    });

    DSU dsu(tot_v);
    vector<vector<int>> mst;

    for (auto& edge : edge_list) { // Corrected to 'for'
        int from_v = edge[0];
        int to_v = edge[1];
        int weight = edge[2];

        if (dsu.find_absolute_parent(from_v) != dsu.find_absolute_parent(to_v)) {
            dsu.union_operation(from_v, to_v);
            mst.push_back({from_v, to_v, weight});
        }

        if ((int)mst.size() == tot_v - 1) {
            break; // MST is complete
        }
    }
    return mst;
}

int main() {
    vector<vector<int>> edge_list = {
        {1, 2, 11}, {1, 3, 13}, {1, 5, 2}, {2, 3, 15}, {2, 4, 8},
        {2, 5, 12}, {2, 7, 6}, {4, 5, 14}, {4, 7, 10}, {4, 8, 17},
        {5, 8, 5}, {6, 7, 21}, {6, 8, 7}, {7, 8, 11}
    };

    int tot_v = 8;
    vector<vector<int>> mst = kruskal(edge_list, tot_v);

    int tot_cost = 0;
    cout << "Edges in the MST:\n";
    for (auto& edge : mst) {
        cout << edge[0] << " - " << edge[1] << " : " << edge[2] << endl;
        tot_cost += edge[2];
    }

    cout << "--------------------\n";
    cout << "Total cost of MST: " << tot_cost << endl;

    return 0;
}