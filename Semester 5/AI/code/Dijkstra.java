import java.util.*;

public class Dijkstra {
    static class Edge {
        int to;
        long weight;

        public Edge(int to, long weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static long[] dijkstra(List<List<Edge>> graph, int src) {
        int n = graph.size();
        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        boolean[] used = new boolean[n];
        dist[src] = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>((i, j) -> Long.compare(dist[i], dist[j]));
        pq.add(src);

        while (!pq.isEmpty()) {
            int u = pq.poll();
            used[u] = true;
            for (Edge edge : graph.get(u)) {
                int v = edge.to;
                long w = edge.weight;
                if (!used[v] && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.add(v);
                }
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        int n = 6; // Number of nodes
        int src = 0; // Source node

        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        // Add edges and weights to the graph
        graph.get(0).add(new Edge(1, 2));
        graph.get(0).add(new Edge(2, 4));
        graph.get(1).add(new Edge(2, 1));
        graph.get(1).add(new Edge(3, 7));
        graph.get(2).add(new Edge(4, 3));
        graph.get(3).add(new Edge(4, 1));
        graph.get(3).add(new Edge(5, 5));
        graph.get(4).add(new Edge(5, 2));

        long[] distances = dijkstra(graph, src);

        for (int i = 0; i < n; i++) {
            System.out.println("Shortest distance from node " + src + " to node " + i + " is " + distances[i]);
        }
    }
}
