// See: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/editorial/
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> myset;
        return find(root, k, myset);
    }

    bool find(TreeNode* root, int k, set<int>& myset) {
        if (!root) return false;

        if (myset.contains(k - root->val)) return true;
        myset.insert(root->val);
        return find(root->left, k, myset) || find(root->right, k, myset);
    }
};

/**
653. Two Sum IV - Input is a BST
Easy

Given the root of a binary search tree and an integer k, return true if there exist two elements 
in the BST such that their sum is equal to k, or false otherwise.
 */
