// Note:
// The solutions below use parent[y] = x,
// this is guaranteed by the assumption that given edges are arranged 
// as [small, big], and it's actually parent[big] = small. 
// Also it seems to require the edges are sorted.
// E.g., 3 nodes (1, 2, 3) form a cycle, 3 pairs are:
// (2,3), (1,3), (1,2). Then this will return true but it should be false.
// --> Well, it turns out the above statement seems false.
// when reverse the edge order, or make it unsorted, or use the "cycle"
// example above, the code below all generate correct result.
// So need more peruse.
// If change parent[y] = x to: parent[x] = y, it also passes 3 tests here.

// Works. Tested. Modified from Solution.
// Better, more clear, by moving check of edges.size() to the beginning.
class Solution2 {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n <= 1) return true;
        if (edges.size() != n - 1) return false;
        
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto edge : edges) {
            int x = find(parent, edge.first);
            int y = find(parent, edge.second);
            if (x == y) return false; // cycle found.
            parent[y] = x;
        }

        return true; //edges.size() == n - 1;
    }

    int find(vector<int> parent, int i) {
        while (i != parent[i]) i = parent[i];
        return parent[i];
    }
};

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
            if (x == y) return false; // cycle found.
            parent[y] = x;
        }

        return edges.size() == n - 1;
    }

    int find(vector<int> & parent, int i) {
        /*if (parent[i] != i) { // this works too.
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
        */
        while (i != parent[i]) {
            i = parent[i];
        }
        return i;
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
