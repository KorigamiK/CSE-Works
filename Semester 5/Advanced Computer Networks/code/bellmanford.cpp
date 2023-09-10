#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct Edge {
  int source, destination, weight;
};

class Graph {
  int V, E;
  vector<Edge> edges;

public:
  Graph(int vertices, int edges);
  void addEdge(int source, int destination, int weight);
  void bellmanFord(int source);
};

Graph::Graph(int vertices, int edges) : V(vertices), E(edges) {}

void Graph::addEdge(int source, int destination, int weight) {
  edges.push_back({source, destination, weight});
}

void Graph::bellmanFord(int source) {
  vector<int> distance(V, numeric_limits<int>::max());
  distance[source] = 0;

  for (int i = 1; i < V; ++i) {
    for (const Edge &edge : edges) {
      int u = edge.source, v = edge.destination, w = edge.weight;
      if (distance[u] != numeric_limits<int>::max() &&
          distance[u] + w < distance[v]) {
        distance[v] = distance[u] + w;
      }
    }
  }

  // Check for negative weight cycles
  for (const Edge &edge : edges) {
    int u = edge.source, v = edge.destination, w = edge.weight;
    if (distance[u] != numeric_limits<int>::max() &&
        distance[u] + w < distance[v]) {
      cout << "Graph contains a negative weight cycle.\n";
      return;
    }
  }

  // Print shortest distances from the source vertex
  cout << "Vertex\tDistance from Source\n";
  for (int i = 0; i < V; ++i) {
    cout << i << "\t" << distance[i] << "\n";
  }
}

int main() {
  int V, E;
  cout << "Enter the number of vertices and edges: ";
  cin >> V >> E;

  Graph graph(V, E);

  for (int i = 0; i < E; ++i) {
    int source, destination, weight;
    cout << "Enter edge " << i + 1 << " (source, destination, weight): ";
    cin >> source >> destination >> weight;
    graph.addEdge(source, destination, weight);
  }

  int source;
  cout << "Enter the source vertex: ";
  cin >> source;

  graph.bellmanFord(source);

  return 0;
}
