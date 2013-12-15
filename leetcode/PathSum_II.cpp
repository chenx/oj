//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/26/2012
// @Last modified: 12/26/2012
//
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > vs;
        vector<int> path;
        ps(root, sum, vs, path);
        return vs;
    }
    
    // Note: vs is passed by reference, path is passed by value (copy).
    void ps(TreeNode * n, int sum, 
            vector<vector<int> > &vs, vector<int> path) {
        if (n == NULL) return;
        
        path.push_back(n->val);
        if (n->val == sum && n->left == NULL && n->right == NULL) {
            vs.push_back(path);
            return;
        }
        
        ps(n->left, sum - n->val, vs, path);
        ps(n->right, sum - n->val, vs, path);
    }
};

/*
Problem:
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

 */