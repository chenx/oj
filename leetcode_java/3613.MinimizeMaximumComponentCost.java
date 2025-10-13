// Same as Solution, no comment.
class Solution2 {
    private int[] parent; 

    public int minCost(int n, int[][] edges, int k) {
        if (n == k) return 0;

        parent = new int[n];
        Arrays.setAll(parent, i -> i);
        Arrays.sort(edges, (a, b) -> a[2] - b[2]);

        int count = n;
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];

            int parentU = find(u), parentV = find(v);
            if (parentU != parentV) {
                parent[parentU] = parentV;
                count -= 1;
                if (count <= k) return weight;
            }
        }
        return 0;
    }

    private int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
}

// From: https://algo.monster/liteproblems/3613
class Solution {
    // Parent array for Union-Find (Disjoint Set Union) data structure
    private int[] parent;

    /**
     * Finds the minimum cost to connect components until we have at most k components.
     * Uses Kruskal's algorithm with Union-Find to build a Minimum Spanning Forest.
     * 
     * @param n     The number of nodes (0-indexed)
     * @param edges Array of edges where each edge is [u, v, weight]
     * @param k     Target number of components
     * @return The minimum cost (maximum edge weight used) to achieve k components
     */
    public int minCost(int n, int[][] edges, int k) {
        if (k == n) {
            return 0;
        }      

        // Initialize Union-Find with each node as its own parent
        parent = new int[n];
        Arrays.setAll(parent, i -> i);
      
        // Sort edges by weight in ascending order for greedy selection
        Arrays.sort(edges, Comparator.comparingInt(edge -> edge[2]));
      
        // Track the current number of connected components
        int componentCount = n;
      
        // Process edges in order of increasing weight
        for (int[] edge : edges) {
            int nodeU = edge[0];
            int nodeV = edge[1];
            int weight = edge[2];
          
            // Find the root parents of both nodes
            int parentU = find(nodeU);
            int parentV = find(nodeV);
          
            // If nodes belong to different components, merge them
            if (parentU != parentV) {
                // Union operation: merge the two components
                parent[parentU] = parentV;
              
                // Decrease component count and check if we've reached target
                componentCount--;
                if (componentCount <= k) {
                    // Return the weight of the last edge added to achieve k components
                    return weight;
                }
            }
        }
      
        // If we can't achieve k components, return 0
        return 0;
    }

    /**
     * Find operation with path compression for Union-Find.
     * Finds the root parent of a node and compresses the path for efficiency.
     * 
     * @param x The node to find the root parent for
     * @return The root parent of node x
     */
    private int find(int x) {
        // Path compression: make every node point directly to root
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
}

/**
3613. Minimize Maximum Component Cost

You are given an undirected connected graph with n nodes labeled from 0 to n - 1 and a 
2D integer array edges where edges[i] = [ui, vi, wi] denotes an undirected edge between 
node ui and node vi with weight wi, and an integer k.

You are allowed to remove any number of edges from the graph such that the resulting graph 
has at most k connected components.

The cost of a component is defined as the maximum edge weight in that component. 
If a component has no edges, its cost is 0.

Return the minimum possible value of the maximum cost among all components after such removals.
 */
