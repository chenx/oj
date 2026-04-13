// From: https://algo.monster/liteproblems/3613
// Time: O(m × log m + m × α(n)), where m is the number of edges and α(n) is the inverse Ackermann function. ~ O(m × log m)
// Space: O(n) where n is the number of nodes.
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        // If k equals n, all nodes are already separate components
        if (k == n) {
            return 0;
        }

        // Initialize parent array for Union-Find (Disjoint Set Union)
        vector<int> parent(n);
        // Initially, each node is its own parent
        ranges::iota(parent, 0);

        // Sort edges by weight in ascending order
        ranges::sort(edges, {}, [](const auto& edge) { return edge[2]; });

        // Find function with path compression for Union-Find
        auto findRoot = [&](this auto&& findRoot, int node) -> int {
            if (parent[node] != node) {
                // Path compression: make every node point directly to root
                parent[node] = findRoot(parent[node]);
            }
            return parent[node];
        };

        // Start with n connected components (each node is isolated)
        int componentsCount = n;

        // Process edges in ascending order of weight
        for (const auto& edge : edges) {
            int nodeU = edge[0];
            int nodeV = edge[1];
            int weight = edge[2];

            // Find roots of both nodes
            int rootU = findRoot(nodeU);
            int rootV = findRoot(nodeV);

            // If nodes belong to different components, merge them
            if (rootU != rootV) {
                // Union operation: merge the two components
                parent[rootU] = rootV;

                // Decrease component count and check if we reached target
                componentsCount--;
                if (componentsCount <= k) {
                    // Return the weight of the edge that achieved the target
                    return weight;
                }
            }
        }

        // If we cannot reduce to k components, return 0
        return 0;
    }
};


/**
3613. Minimize Maximum Component Cost
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given an undirected connected graph with n nodes labeled from 0 to n - 1 and a 
2D integer array edges where edges[i] = [ui, vi, wi] denotes an undirected edge between 
node ui and node vi with weight wi, and an integer k.

You are allowed to remove any number of edges from the graph such that the resulting 
graph has at most k connected components.

The cost of a component is defined as the maximum edge weight in that component. If a 
component has no edges, its cost is 0.

Return the minimum possible value of the maximum cost among all components after such removals.

 

Example 1:

Input: n = 5, edges = [[0,1,4],[1,2,3],[1,3,2],[3,4,6]], k = 2

Output: 4
 */
