// From: https://algo.monster/liteproblems/2065
// Time Complexity: O(n + m + 4^(maxTime/min(time_j)))
// Space Complexity: O(n + m + maxTime/min(time_j))
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
      
        // Build adjacency list representation of the graph
        // Each node stores pairs of (neighbor_node, time_cost)
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], time = edge[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }
      
        // Track visited nodes to avoid counting their values multiple times
        vector<bool> visited(n, false);
        visited[0] = true;
      
        // Maximum path quality found so far
        int maxQuality = 0;
      
        // DFS function to explore all valid paths
        // Parameters:
        // - currentNode: current node in the path
        // - timeCost: accumulated time cost so far
        // - pathValue: accumulated value of unique nodes visited
        function<void(int, int, int)> dfs = [&](int currentNode, int timeCost, int pathValue) {
            // Update answer when we return to node 0
            if (currentNode == 0) {
                maxQuality = max(maxQuality, pathValue);
            }
          
            // Explore all neighbors
            for (const auto& [nextNode, edgeTime] : graph[currentNode]) {
                // Only proceed if we have enough time remaining
                if (timeCost + edgeTime <= maxTime) {
                    if (visited[nextNode]) {
                        // Node already visited, don't add its value again
                        dfs(nextNode, timeCost + edgeTime, pathValue);
                    } else {
                        // Mark as visited and add its value
                        visited[nextNode] = true;
                        dfs(nextNode, timeCost + edgeTime, pathValue + values[nextNode]);
                        // Backtrack: unmark for other paths to use
                        visited[nextNode] = false;
                    }
                }
            }
        };
      
        // Start DFS from node 0 with initial time 0 and value of node 0
        dfs(0, 0, values[0]);
      
        return maxQuality;
    }
};


/**
2065. Maximum Path Quality of a Graph
Solved
Hard
Topics
conpanies iconCompanies
Hint

There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). You are given a 
0-indexed integer array values where values[i] is the value of the ith node. You are also given 
a 0-indexed 2D integer array edges, where each edges[j] = [uj, vj, timej] indicates that there 
is an undirected edge between the nodes uj and vj, and it takes timej seconds to travel between 
the two nodes. Finally, you are given an integer maxTime.

A valid path in the graph is any path that starts at node 0, ends at node 0, and takes at most 
maxTime seconds to complete. You may visit the same node multiple times. The quality of a valid 
path is the sum of the values of the unique nodes visited in the path (each node's value is 
added at most once to the sum).

Return the maximum quality of a valid path.

Note: There are at most four edges connected to each node.

 

Example 1:

Input: values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
Output: 75
 */
