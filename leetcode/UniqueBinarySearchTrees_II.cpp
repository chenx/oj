//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Recursive procedure.
 * Note that trees at the same level will share some of their children.
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return g(1, n);
    }
    
    vector<TreeNode *> g(int left, int right) {
        vector<TreeNode *> ts;
        if (left > right) {
            ts.push_back(NULL);
            return ts;
        }
        if (left == right) {
            ts.push_back(new TreeNode(left));
            return ts;
        }
        
        for (int i = left; i <= right; i ++) {
            vector<TreeNode *> lefts = g(left, i - 1);
            vector<TreeNode *> rights = g(i + 1, right);
            for (int j = 0; j < lefts.size(); j ++) {
                for (int k = 0; k < rights.size(); k ++) {
                    TreeNode * n = new TreeNode(i);
                    n->left = lefts[j];
                    n->right = rights[k];
                    ts.push_back(n);
                }
            }
        }
        
        return ts;
    }
};


/*
Problem:

Given n, generate all structurally unique BST's (binary search trees) 
that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */