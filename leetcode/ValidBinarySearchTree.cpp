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
    
    // This has an issue if a node's value is INT_MIN or INT_MAX.
    bool isValid(TreeNode * n, int minv, int maxv) {
        if (n == NULL) return true;
        return (n->val > minv && n->val < maxv) &&
               isValid(n->left, minv, n->val) &&
               isValid(n->right, n->val, maxv);
    }

    // Method 2. This fixes the issue when a node's value equals INT_MIN or INT_MAX.
    // Call with: bst(root, NULL, INT_MIN, INT_MAX).
    // NOTE: Seems Method 2 is wrong? {3,1,5,0,2,4,6,#,#,#,3} should be false, but returns true.
    // So Method 2 is NOT correct. 10-16-2014.
    bool bst(TreeNode * n, TreeNode * parent, int L, int R) {
        if (n == NULL) return true;

        return (n->val >= L && n->val <= R &&
                (parent == NULL ? true : n->val != parent->val) &&
                bst(n->left, n, L, n->val) &&
                bst(n->right, n, n->val, R));
    }

    // Method 3. This works! Use long long type to overcome overflow issue.
    void IsBST2(TreeNode * root) { bst2(root, INT_MIN - 11l, INT_MAX + 1ll); }

    bool bst2(TreeNode * root, long  long MIN, long long MAX){
        if (root == NULL) return true;
        return root->val < MAX && root->val > MIN &&
               bst2(root->left, MIN, root->val) && bst2(root->right, root->val, MAX);
    }
};
