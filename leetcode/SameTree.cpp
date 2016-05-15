//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//

// Works too.
class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (p == NULL && q == NULL) || 
               (p != NULL && q != NULL && p->val == q->val && 
                isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
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
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (NULL == p && NULL == q) return true;
        if (NULL == p || NULL == q) return false;
        
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


/**
Same Tree  
Difficulty: Easy

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and 
the nodes have the same value. 
 */
