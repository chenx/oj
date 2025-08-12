//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// Works.
class Solution4 {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, (long long) INT_MIN - 1, (long long) INT_MAX + 1);
        // Or: return helper(root, INT_MIN - 1ll, INT_MAX + 1ll);
    }

    bool helper(TreeNode* root, long long L, long long R) {
        if (! root) return true;
        return (root->val > L && root->val < R) &&
          helper(root->left, L, root->val) &&
          helper(root->right, root->val, R);
    }
};

// Works. Tested.
// Use NULL for the 2 extreme cases, to avoid INT_MIN, INT_MAX issue.
class Solution3 {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
    }
    
    bool validate(TreeNode * root, TreeNode * left, TreeNode * right) {
        if (NULL == root) return true;
        
        return (left == NULL || left->val < root->val) &&
               (right == NULL || right->val > root->val) &&
               validate(root->left, left, root) &&
               validate(root->right, root, right);
    }
};

// This works too. O(1)space, O(n) time. From CC150 5ed. Page 226. 
// This also works when a node's value can be INT_MIN or INT_MAX.
// Basically, NULL value of prev is used to handle the case when left node's value is INT_MIN.
// This is equivalent to another O(n) solution: do inorder traversal, verify "<" relation of adjacent elements.
class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode * prev = NULL;
        return valid(root, prev);
    }
    
    bool valid(TreeNode * n, TreeNode *& prev) {
        if (! n) return true;
        
        if (! valid(n->left, prev)) return false;
        
        if (prev && prev->val >= n->val) return false;
        prev = n;
        
        if (! valid(n->right, prev)) return false;
        
        return true;
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


/**
Validate Binary Search Tree
Difficulty: Medium

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
 */
