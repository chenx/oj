// BFS.
// Time: O(n + m). n - number of vertices, m - number of edges;
// Space: O(m + n)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int, set<int>> graph;
        for (auto& edge : edges) { // O(m)
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        if (source == destination) return true;

        queue<int> q;
        q.push(source);

        set<int> visited;
        visited.insert(source);

        while (! q.empty()) { // O(n)
            int node = q.front();
            q.pop();

            for (int nextNode : graph[node]) {
                if (! visited.contains(nextNode)) {
                    if (nextNode == destination) return true;

                    q.push(nextNode);
                    visited.insert(nextNode);
                }
            }
        }
        return false;
    }
};


/**
1971. Find if Path Exists in Graph
Easy

There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes 
a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, 
and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source 
to destination, or false otherwise.

 

Example 1:

Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
 */
