// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (! root) {
            return subRoot == NULL;
        }

        if (root->val == subRoot->val) {
            if (isSameTree(root, subRoot)) return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (! root && ! subRoot) return true;
        if (! root || ! subRoot) return false;
        return root->val == subRoot->val && 
            isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
};


/**
572. Subtree of Another Tree
Easy

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with 
the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's 
descendants. The tree tree could also be considered as a subtree of itself.

 

Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
 */
