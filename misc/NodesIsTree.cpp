/**
 * Given an interface Node. Node has method getParent().
 * Input is a collectio of nodes, check if the nodes belong to a tree.
 * Google interview problem.
 *
 * @from: http://www.mitbbs.com/article_t/JobHunting/32829537.html
 * @by: X.C.
 * @since: 11/14/2014
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#ifndef unordered_set
#define unordered_set set
#endif

struct TreeNode {
    int val;
    TreeNode * parent;
};

//
// Simple solution: check if all nodes can trace back to the same root.
// check no cycle exists.
// Note: this solution is not tested thoroughly with test cases.
//
class Solution {
public:
    TreeNode * getParent(TreeNode * n) {
        return n->parent;
    }
    
    bool isTree(vector<TreeNode *> nodes) {
        if (nodes.size() == 0) return true;
    
        TreeNode * root = getRoot(nodes[0]);
        if (root == NULL) return false;
    
        for (int i = 1; i < nodes.size(); ++ i) {
            if (getRoot(nodes[i]) != root) return false;
        }
        return true;
    }
    
    // getParent(n): return NULL if no parent
    TreeNode * getRoot(TreeNode * n) {
        unordered_set<TreeNode *> s;
    
        for (TreeNode * p = getParent(n); p != NULL; p = getParent(n)) {
            if (s.find(n) != s.end()) return NULL; // cycle found
            s.insert(n);
            n = p;
        }
    
        return n;
    }
};

//
// Improved linear solution: store visited nodes in a set. 
// Visit each node only once.
// Note: this solution is not tested thoroughly with test cases.
//
class Solution2 {
public:
    TreeNode * getParent(TreeNode * n) {
        return n->parent;
    }
        
    bool isTree(vector<TreeNode *> nodes) {
        if (nodes.size() == 0) return true;
        unordered_set<TreeNode *> visited; // store found nodes.
    
        TreeNode * root = getRoot(nodes[0], NULL, visited);
        if (root == NULL) return false;
    
        for (int i = 1; i < nodes.size(); ++ i) {
            if (root != getRoot(nodes[i], root, visited)) return false;
        }
        return true;
    }
    
    // getParent(n): return NULL if no parent
    TreeNode * getRoot(TreeNode * n, TreeNode * root,
                     unordered_set<TreeNode *> &visited) {
        if (n == root || visited.find(n) != visited.end()) return root;
        unordered_set<TreeNode *> s;
    
        for (TreeNode * p = getParent(n); p != NULL; p = getParent(n)) {
            visited.insert(n);
            if (visited.find(p) != visited.end()) return root;
    
            if (s.find(n) != s.end()) return NULL; // cycle found
            s.insert(n);
            n = p;
        }
    
        return n;
    }
};

int main() {
    return 0;
}
