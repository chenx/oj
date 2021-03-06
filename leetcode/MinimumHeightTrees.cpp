// Works too. Tested.
class Solution4 {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 0) return vector<int>();
        if (n == 1) return vector<int>(1, 0);
        
        map<int, set<int>> m;
        for (auto e : edges) {
            m[e.first].insert(e.second);
            m[e.second].insert(e.first);
        }
        
        vector<int> leaves;
        for (auto e : m) {
            if (e.second.size() == 1) 
                leaves.push_back(e.first);
        }
        
        int count = n;
        while (count > 2) {
            vector<int> new_leaves;
            for (int leaf : leaves) {
                int j = *m[leaf].begin(); // the other node of the edge.
                m[j].erase(leaf);
                //m[leaf].erase(j); // no need to erase, as new_leaves is used.
                if (m[j].size() == 1) {
                    new_leaves.push_back(j);
                }
                -- count;
            }
            leaves = new_leaves;
        }
        
        return leaves;
    }
};

// Works too. Modified from Solution2, more clean.
class Solution3 {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        
        unordered_map<int, vector<int>> adj;
        for (auto e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        
        vector<int> leaves;
        for (auto a : adj) {
            if (a.second.size() == 1) leaves.push_back(a.first);
        }
        
        while (n > 2) {
            n -= leaves.size();

            vector<int> newLeaves;
            for (int leaf : leaves) {
                int n = adj[leaf][0];
                //adj[leaf].clear(); // no need to clear this. But ok too.
                adj[n].erase(find(adj[n].begin(), adj[n].end(), leaf));
                if (adj[n].size() == 1) newLeaves.push_back(n);
            }
            leaves = newLeaves;
        }
        
        return leaves;
    }
};

// Works too. But Solution is more clean.
// Advantage is no use of hardcoded 0~n-1 as node label, just map instead.
class Solution2 {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        
        unordered_map<int, vector<int>> adj;
        for (auto e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        
        vector<int> leaves;
        for (auto a : adj) {
            if (a.second.size() == 1) leaves.push_back(a.first);
        }
        
        while (adj.size() > 2) {
            vector<int> newLeaves;
            for (int leaf : leaves) {
                int n = adj[leaf][0];
                // remove leaf from the other node's kneighbors.
                adj[n].erase(find(adj[n].begin(), adj[n].end(), leaf)); 
                if (adj[n].size() == 1) newLeaves.push_back(n);
                
                adj.erase(adj.find(leaf)); // remove leaf
            }
            
            leaves = newLeaves;
        }
        
        return leaves;
    }
};

// Works. Tested. From: http://algobox.org/minimum-height-trees/
/*
Solution

First let’s review some statement for tree in graph theory:
1. A tree is an undirected graph in which any two vertices are connected by exactly one path.
2. Any connected graph who has n nodes with n-1 edges is a tree.
3. The degree of a vertex of a graph is the number of edges incident to the vertex.
4. A leaf is a vertex of degree 1. An internal vertex is a vertex of degree at least 2.
5. A path graph is a tree with two or more vertices that is not branched at all.
6. A tree is called a rooted tree if one vertex has been designated the root.
7. The height of a rooted tree is the number of edges on the longest downward path between root and a leaf.

OK. Let’s stop here and look at our problem.

Our problem want us to find the minimum height trees and return their 
root labels. First we can think about a simple case — a path graph.

For a path graph of n nodes, find the minimum height trees is trivial. 
Just designate the middle point(s) as roots.

Despite its triviality, let design a algorithm to find them.

Suppose we don’t know n, nor do we have random access of the nodes. 
We have to traversal. It is very easy to get the idea of two pointers. 
One from each end and move at the same speed. When they meet or they 
are one step away, (depends on the parity of n), we have the roots 
we want.

This gives us a lot of useful ideas to crack our real problem.

For a tree we can do some thing similar. We start from every end, 
by end we mean vertex of degree 1 (aka leaves). We let the pointers 
move the same speed. When two pointers meet, we keep only one of 
them, until the last two pointers meet or one step away we then 
find the roots.

It is easy to see that the last two pointers are from the two 
ends of the longest path in the graph.

The actual implementation is similar to the BFS topological sort. 
Remove the leaves, update the degrees of inner vertexes. Then remove 
the new leaves. Doing so level by level until there are 2 or 1 
nodes left. What’s left is our answer!

The time complexity and space complexity are both O(n).

Note that for a tree we always have V = n, E = n-1.
 */
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        
        vector<set<int>> adj(n); // unordered_set works too.
        for (auto edge : edges) {
            adj[edge.first].insert(edge.second);
            adj[edge.second].insert(edge.first);
        }
     
        vector<int> leaves;
        for (int i = 0; i < n; ++i)
            if (adj[i].size() == 1) leaves.push_back(i);
     
        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int i : leaves) {
                int j = * adj[i].begin(); // i is leaf, then adj[i] contains only 1 element.
                adj[j].erase(i);
                if (adj[j].size() == 1) newLeaves.push_back(j);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};


/**
Minimum Height Trees
Difficulty: Medium

For a undirected graph with tree characteristics, we can choose 
any node as the root. The result graph is then a rooted tree. 
Among all possible rooted trees, those with minimum height are 
called minimum height trees (MHTs). Given such a graph, write a 
function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. 
You will be given the number n and a list of undirected edges 
(each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. 
Since all edges are undirected, [0, 1] is the same as [1, 0] 
and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3

return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5

return [3, 4]

Hint:

    How many MHTs can a graph have at most?
    (Answer: 1 or 2)

Note:

(1) According to the definition of tree on Wikipedia: “a tree is 
    an undirected graph in which any two vertices are connected 
    by exactly one path. In other words, any connected graph 
    without simple cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the 
    longest downward path between the root and a leaf. 
 */
