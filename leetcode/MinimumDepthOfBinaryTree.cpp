//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
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

// Works too. Tested. Although Solution is preferred.
class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        
        int L = root->left == NULL ? INT_MAX : minDepth(root->left),
            R = root->right == NULL ? INT_MAX : minDepth(root->right);
        
        int d = min(L, R);
        if (d == INT_MAX) d = 0;
        
        return 1 + d;
    }
};

// Works. Preferred answer.
class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        if (root->left == NULL && root->right != NULL) return 1 + minDepth(root->right);
        if (root->left != NULL && root->right == NULL) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};


/**
Minimum Depth of Binary Tree
Difficulty: Easy

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.
 */
