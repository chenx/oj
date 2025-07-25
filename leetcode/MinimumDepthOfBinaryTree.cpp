//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//

// Works. Use level order traversal. Time/Space: O(2^minHeight - 1). 
// This is more space efficient if tree is not balanced.
// But if tree is balanced, Solution is more efficent.
class Solution4 {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
 
        queue<TreeNode *> q;
        q.push(root);
         
        int minH = 0;
        while (! q.empty()) {
            ++ minH;
            for (int ct = q.size(); ct > 0; -- ct) { // level minH
                TreeNode * n = q.front();
                q.pop();
           
                if (n->left == NULL && n->right == NULL) return minH;
             
                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
        }
         
        return minH;
    }
};

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
class Solution3 {
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
class Solution2 {
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

class Solution {
public:
   int minDepth(TreeNode* root) {
       if (!root) return 0;
       if (!root->left && !root->right) return 1;
       if (!root->left) return 1 + minDepth(root->right);
       if (!root->right) return 1 + minDepth(root->left);
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
