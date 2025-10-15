// Note the handling of empty set.
// Time complexity: O(E+V2)
// Space complexity: O(E)
class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        int maxRank = 0;
        Map<Integer, Set<Integer>> adj = new HashMap<>();
        // Construct adjency list 'adj', where adj[node] stores all nodes connected to 'node'.
        for (int[] road : roads) {
            adj.computeIfAbsent(road[0], k -> new HashSet<>()).add(road[1]);
            adj.computeIfAbsent(road[1], k -> new HashSet<>()).add(road[0]);
            // if (adj.get(road[0]) == null) {
            //     adj.put(road[0], new HashSet<Integer>());
            // }
            // adj.get(road[0]).add(road[1]);
            // if (adj.get(road[1]) == null) {
            //     adj.put(road[1], new HashSet<Integer>());
            // }
            // adj.get(road[1]).add(road[0]);
        }

        // Iterate on each possible pair of nodes.
        for (int node1 = 0; node1 < n; ++node1) {
            for (int node2 = node1 + 1; node2 < n; ++node2) {
                int currentRank = adj.getOrDefault(node1, Collections.emptySet()).size() +
                                  adj.getOrDefault(node2, Collections.emptySet()).size();

                if (adj.getOrDefault(node1, Collections.emptySet()).contains(node2)) {
                    --currentRank;
                }
                maxRank = Math.max(maxRank, currentRank);
            }
        }
        // Return the maximum network rank.
        return maxRank;
    }
}

/**
1615. Maximal Network Rank

There is an infrastructure of n cities with some number of roads connecting these cities. 
Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected 
roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
 */
