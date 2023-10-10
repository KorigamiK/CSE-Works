#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int INFINITY = numeric_limits<int>::max();

struct Router {
  int id;
  vector<int> distanceVector;
  vector<vector<int>> neighborsDistanceVectors;
};

void initializeRouter(Router &router, int numNodes, int routerId) {
  router.id = routerId;
  router.distanceVector.resize(numNodes, INFINITY);
  router.distanceVector[routerId] = 0;

  router.neighborsDistanceVectors.resize(numNodes,
                                         vector<int>(numNodes, INFINITY));
}

void updateDistanceVector(Router &router, int destination, int cost) {
  router.distanceVector[destination] = cost;
}

void updateNeighborDistanceVector(Router &router, int neighborId,
                                  const vector<int> &distanceVector) {
  router.neighborsDistanceVectors[neighborId] = distanceVector;
}

void printDistanceVector(const vector<int> &distanceVector) {
  for (int distance : distanceVector) {
    cout << (distance == INFINITY ? "INF" : to_string(distance)) << "\t";
  }
  cout << endl;
}

void printRouterInfo(const Router &router, int numNodes) {
  cout << "Router " << router.id << " Distance Vector: ";
  printDistanceVector(router.distanceVector);
  for (int i = 0; i < numNodes; ++i) {
    cout << "From Neighbor " << i << ": ";
    printDistanceVector(router.neighborsDistanceVectors[i]);
  }
  cout << endl;
}

bool updateDistanceVectorBasedOnNeighbors(Router &router, int numNodes) {
  bool updated = false;
  for (int destination = 0; destination < numNodes; ++destination) {
    int minCost = router.distanceVector[destination];
    for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
      if (neighbor != router.id) {
        minCost = min(minCost,
                      router.neighborsDistanceVectors[neighbor][destination]);
      }
    }
    if (minCost != router.distanceVector[destination]) {
      router.distanceVector[destination] = minCost;
      updated = true;
    }
  }
  return updated;
}

int main() {
  int numNodes, routerId;
  cout << "Enter the number of nodes: ";
  cin >> numNodes;
  cout << "Enter the router ID (0 to " << numNodes - 1 << "): ";
  cin >> routerId;

  Router router;
  initializeRouter(router, numNodes, routerId);

  bool updated = true;
  while (updated) {
    updated = false;
    cout << "Enter updated distance vector from neighbors (routerID "
            "destinationID cost), -1 to stop:\n";
    int neighborId, destination, cost;
    while (true) {
      cin >> neighborId;
      if (neighborId == -1) {
        break;
      }
      cin >> destination >> cost;
      updateNeighborDistanceVector(router, neighborId,
                                   router.neighborsDistanceVectors[neighborId]);
      updateDistanceVector(router, destination, cost);
    }

    cout << "Router " << router.id << " Distance Vector before update:\n";
    printRouterInfo(router, numNodes);
    updated = updateDistanceVectorBasedOnNeighbors(router, numNodes);
    cout << "Router " << router.id << " Distance Vector after update:\n";
    printRouterInfo(router, numNodes);
  }

  return 0;
}
