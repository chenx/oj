// Time complexity: O(E+V2)
// Space complexity: O(E)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank = 0;
        unordered_map<int, unordered_set<int>> adj;
        for (auto& road : roads) {
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }

        for (int node1 = 0; node1 < n; ++node1) {
            for (int node2 = node1 + 1; node2 < n; ++node2) {
                int currentRank = adj[node1].size() + adj[node2].size();
                if (adj[node2].contains(node1)) {
                    --currentRank;
                }
                maxRank = max(maxRank, currentRank);
            }
        }
        return maxRank;
    }
};

/**
1615. Maximal Network Rank

There is an infrastructure of n cities with some number of roads connecting these cities. 
Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected 
roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
 */
