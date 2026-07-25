// See https://leetcode.com/problems/redundant-connection-ii/editorial/
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
private:
    struct OrbitResult {
        int node;
        unordered_set<int> seen;

        OrbitResult(int n, unordered_set<int> s) : node(n), seen(move(s)) {}
    };

    OrbitResult orbit(int node, unordered_map<int, int>& parent) {
        unordered_set<int> seen;

        while (parent.contains(node) && !seen.contains(node)) {
            seen.insert(node);
            // node = parent.at(node);
            node = parent[node]; // valid since parent.contains[node] is true
        }

        return OrbitResult(node, move(seen));
    }

    void dfs(int node, unordered_map<int, vector<int>>& children, vector<bool>& seen) {
        if (seen[node]) {
            return;
        }
        seen[node] = true;

        if (children.contains(node)) {
            for (int child : children[node]) {
                dfs(child, children, seen);
            }
        }
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        unordered_map<int, int> parent;
        vector<vector<int>> candidates;

        // Find nodes with two parents.
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (parent.contains(v)) {
                candidates.push_back({parent[v], v});
                candidates.push_back(edge);
            } else {
                parent[v] = u;
            }
        }

        int root = orbit(1, parent).node;

        // No node has two parents. Therefore, there must be a cycle.
        if (candidates.empty()) {
            unordered_set<int> cycle = orbit(root, parent).seen;

            vector<int> ans = {0, 0};
            for (const auto& edge : edges) {
                if (cycle.contains(edge[0]) && cycle.contains(edge[1])) {
                    ans = edge;
                }
            }

            return ans;
        }

        // Build children adjacency list.
        unordered_map<int, vector<int>> children;
        for (const auto& [v, pv] : parent) {
            children[pv].push_back(v);
        }

        // DFS from root.
        vector<bool> seen(N + 1, false);
        seen[0] = true;

        dfs(root, children, seen);

        for (bool b : seen) {
            if (!b) {
                return candidates[0];
            }
        }

        return candidates[1];
    }
};

/**
685. Redundant Connection II
Solved
Hard
Topics
conpanies iconCompanies

In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) 
for which all other nodes are descendants of this node, plus every node has exactly one parent, 
except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values 
from 1 to n), with one additional directed edge added. The added edge has two different vertices 
chosen from 1 to n, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that 
represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there 
are multiple answers, return the answer that occurs last in the given 2D-array.

 

Example 1:

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:

Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
Output: [4,1]
 */
