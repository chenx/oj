// Works. Tested. 
// Modified from: https://leetcode.com/discuss/85859/simple-1ms-java-union-find-solution
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n <= 1) return true;
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto edge : edges) {
            int x = find(parent, edge.first);
            int y = find(parent, edge.second);
            if (x == y) return false;
            parent[y] = x;
        }

        return edges.size() == n - 1;
    }

    int find(vector<int> & parent, int i) {
        /*if (parent[i] != i) { // this works too.
            parent[i] = find(parent, parent[i]);
        }*/
        while (i != parent[i]) {
            i = parent[i];
        }
        return parent[i];
    }
};


/**
Graph Valid Tree
Difficulty: Medium

Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
(each edge is a pair of nodes), write a function to check whether 
these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

1. Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? 
   Is this case a valid tree?
2. According to the definition of tree on Wikipedia: “a tree is an undirected 
   graph in which any two vertices are connected by exactly one path. In other 
  words, any connected graph without simple cycles is a tree.”

Note: you can assume that no duplicate edges will appear in edges. Since all 
edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear 
together in edges.

 */
