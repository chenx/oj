// Time complexity: O(N⋅α(N)) =~ O(N)
// Space: O(N)
class Solution {
    class UnionFind {
        public:
        void add(int x) {
            if (parent.contains(x)) return;

            parent[x] = x;
            rank[x] = 0;
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        void get_union(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            
            int rx = rank[x], ry = rank[y];
            if (rx < ry) {
                parent[x] = y;
            } else if (ry < rx) {
                parent[y] = x;
            } else {
                parent[y] = x;
                rank[x] ++;
            }
        }

        const unordered_map<int, int>& get_parent_map() const {
            return parent;
        }
        
        private:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf;
        for (auto e : edges) {
            int a = e[0], b = e[1];
            uf.add(a);
            uf.add(b);
            if (uf.find(a) == uf.find(b)) {
                return e;
            } else {
                uf.get_union(a, b);
            }
        }
        return {};
    }
};

/**
684. Redundant Connection
Solved
Medium
Topics
conpanies iconCompanies

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 */
