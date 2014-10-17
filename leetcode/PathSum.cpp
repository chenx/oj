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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        
        // It's asking root to leaf, so last node must be a leaf.
        if (root->val == sum && 
            root->left == NULL &&
            root->right == NULL) return true;
        
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
    
};


class Solution2 {
public:
    // This works too.
    bool hasPathSum(TreeNode *root, int sum) {
        if (! root) return false;
        
        sum -= root->val;
        if (root->left && root->right) {
            return hasPathSum(root->left, sum) ||
                   hasPathSum(root->right, sum);
        }
        else if (root->left) {
            return hasPathSum(root->left, sum);
        }
        else if (root->right) {
            return hasPathSum(root->right, sum);
        }
        else {
            return sum == 0;
        }
    }
    
    // This works too. Most succinct.
    bool hasPathSum2(TreeNode *root, int sum) {
        if (! root) return false;
        
        //if (root->val == sum) { // note, this does not work.
        //    return root->left == NULL && root->right == NULL;
        //}

        sum -= root->val;

        if (! root->left && ! root->right) {
            return 0 == sum;
        }
        
        return hasPathSum(root->left, sum) ||
               hasPathSum(root->right, sum);
    }
};

//
// This works too, and is shorter.
//
class Solution3 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (! root) return false;
        
        if (root->left == NULL && root->right == NULL) {
            return root->val == sum;
        }
        
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};


/*
Problem:

Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

 */
