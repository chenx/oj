// Works. 
// See: https://leetcode.com/problems/is-graph-bipartite/editorial/
// Time: O(n+v)
// Space: O(n)
class Solution2 {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        for (int i = 0; i < n; ++ i) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;
            }
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int j : graph[node]) {
                    if (color[j] == -1) {
                        q.push(j);
                        color[j] = 1 - color[node];
                    } else if (color[j] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};


// BFS / DFS with coloring.
// Time: O(n+v)
// Space: O(n)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++ i) {
            if (color[i] == -1) {
                color[i] = 0; // 1 also works.
                // Both dfs and bfs work.
                // if (! dfs(graph, color, i)) return false;
                if (!bfs(graph, color, i)) return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int i) {
        for (int node : graph[i]) {
            if (color[node] == color[i]) return false;
            if (color[node] == -1) {
                color[node] = 1 - color[i];
                if (!dfs(graph, color, node)) return false;
            }
        }
        return true;
    }

    bool bfs(vector<vector<int>>& graph, vector<int>& color, int i) {
        queue<int> q;
        q.push(i);

        while (! q.empty()) {
            int node = q.front();
            q.pop();

            for (int nextNode : graph[node]) {
                if (color[nextNode] == color[node]) return false;
                if (color[nextNode] == -1) {
                    color[nextNode] = 1 - color[node];
                    q.push(nextNode);
                }
            }
        }
        return true;
    }
};


/**
785. Is Graph Bipartite?
Medium

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, 
where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected 
edge between node u and node v. The graph has the following properties:

    There are no self-edges (graph[u] does not contain u).
    There are no parallel edges (graph[u] does not contain duplicate values).
    If v is in graph[u], then u is in graph[v] (the graph is undirected).
    The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph 
connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
 */
