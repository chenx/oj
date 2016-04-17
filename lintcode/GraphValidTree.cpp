// Union find
class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n <= 1) return true;
        if (edges.size() != n - 1) return false;
        
        vector<int> parent(n);
        for (int i = 0; i < n; ++ i) parent[i] = i;
        
        for (int i = 0; i < edges.size(); ++ i) {
            int x = findParent(edges[i][0], parent), 
                y = findParent(edges[i][1], parent);
            if (x == y) return false;
            parent[y] = x;
        }
        
        return true;
    }
    
    int findParent(int x, vector<int> & parent) {
        while (x != parent[x]) x = parent[x];
        return x;
    }
};


/**
Graph Valid Tree

Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
(each edge is a pair of nodes), write a function to check whether these 
edges make up a valid tree.

Notice

You can assume that no duplicate edges will appear in edges. Since all 
edges are undirected, [0, 1] is the same as [1, 0] and thus will not 
appear together in edges.

Example

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

 */
