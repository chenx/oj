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
 * Note: >= and =< are not considered valid.
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
    
    bool isValid(TreeNode * n, int minv, int maxv) {
        if (n == NULL) return true;
        return (n->val > minv && n->val < maxv) &&
               isValid(n->left, minv, n->val) &&
               isValid(n->right, n->val, maxv);
    }
};
