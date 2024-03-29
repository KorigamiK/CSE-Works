import java.util.*;

class Node implements Comparable<Node> {
    int x, y, cost, heuristic;
    Node parent;

    public Node(int x, int y, int cost, int heuristic, Node parent) {
        this.x = x;
        this.y = y;
        this.cost = cost;
        this.heuristic = heuristic;
        this.parent = parent;
    }

    public int compareTo(Node other) {
        return Integer.compare(this.cost + this.heuristic, other.cost + other.heuristic);
    }
}

public class AStar {
    public static List<Node> astar(int[][] grid, int startX, int startY, int endX, int endY) {
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        PriorityQueue<Node> openSet = new PriorityQueue<>();
        Set<Node> closedSet = new HashSet<>();

        Node startNode = new Node(startX, startY, 0, heuristic(startX, startY, endX, endY), null);
        openSet.add(startNode);

        while (!openSet.isEmpty()) {
            Node current = openSet.poll();

            if (current.x == endX && current.y == endY) {
                // Reconstruct and return the path.
                List<Node> path = new ArrayList<>();
                while (current != null) {
                    path.add(current);
                    current = current.parent;
                }
                Collections.reverse(path);
                return path;
            }

            closedSet.add(current);

            for (int i = 0; i < 4; i++) {
                int newX = current.x + dx[i];
                int newY = current.y + dy[i];

                if (isValid(newX, newY, grid) && !closedSet.contains(new Node(newX, newY, 0, 0, null))) {
                    int newCost = current.cost + 1;
                    int heuristic = heuristic(newX, newY, endX, endY);
                    Node neighbor = new Node(newX, newY, newCost, heuristic, current);

                    if (!openSet.contains(neighbor) || newCost < neighbor.cost) {
                        openSet.add(neighbor);
                    }
                }
            }
        }

        return null; // No path found.
    }

    public static boolean isValid(int x, int y, int[][] grid) {
        return x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && grid[x][y] == 0;
    }

    public static int heuristic(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    public static void main(String[] args) {
        int[][] grid = {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0}
        };

        int startX = 0;
        int startY = 0;
        int endX = 4;
        int endY = 4;

        List<Node> path = astar(grid, startX, startY, endX, endY);

        if (path != null) {
            System.out.println("Shortest path length: " + (path.size() - 1)); // Subtract 1 for the starting node.
            System.out.println("Path: ");
            for (Node node : path) {
                System.out.println("(" + node.x + ", " + node.y + ")");
            }
        } else {
            System.out.println("No path found.");
        }
    }
}
