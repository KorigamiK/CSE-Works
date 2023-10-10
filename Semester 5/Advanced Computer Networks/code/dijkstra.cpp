#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;

void dijkstra(vector<vector<pair<int, ll>>> &G, int src, vector<ll> &dist) {
  vector<bool> used(G.size(), false);
  dist[src] = 0;
  auto cmp = [&](int i, int j) { return dist[i] > dist[j]; };
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  pq.push(src);
  while (!pq.empty()) {
    auto u = pq.top();
    pq.pop();
    used[u] = true;
    for (auto [v, w] : G[u]) {
      if (!used[v] && dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push(v);
      }
    }
  }
}

int main() {
  int n, m; // Number of nodes and edges respectively
  cin >> n >> m;

  vector<vector<pair<int, ll>>> G(n); // Initialize the graph with n nodes

  // Read the edges and their weights
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
  }

  int src; // Source node
  cin >> src;

  vector<ll> dist(n, LLONG_MAX); // Initialize the distance vector with maximum values

  
  dijkstra(G, src, dist); // Run Dijkstra's algorithm

  cout << "Shortest distances from node " << src << ":\n";
  for (int i = 0; i < n; ++i)
    cout << "Node " << i << ": "
         << (dist[i] == LLONG_MAX ? "INFINITY" : to_string(dist[i])) << "\n";
  
  return 0;
}
