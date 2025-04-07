#include <iostream>
#include <vector>
#include <tuple>

class WeightedGraph {
private:
    int vertices; // Number of vertices
    std::vector<std::vector<std::pair<int, int>>> adjList; // Adjacency list with weights

public:
    // Constructor
    WeightedGraph(int v) : vertices(v), adjList(v) {}

    // Add a weighted edge to the graph
    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // For undirected graph
    }

    // Display the weighted graph
    void display() {
        for (int i = 0; i < vertices; ++i) {
            std::cout << i << ": ";
            for (const auto& neighbor : adjList[i]) {
                std::cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};
class Graph {
private:
    int vertices; // Number of vertices
    std::vector<std::vector<int>> adjList; // Adjacency list representation

public:
    // Constructor
    Graph(int v) : vertices(v), adjList(v) {}

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Display the graph
    void display() {
        for (int i = 0; i < vertices; ++i) {
            std::cout << i << ": ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int V = 5; // Number of vertices
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    std::cout << "Graph representation (Adjacency List):" << std::endl;
    g.display();

    return 0;
}