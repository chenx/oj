// Better than Solution.
// From: https://leetcode.com/problems/trim-a-binary-search-tree/editorial/
// Time: O(n)
// Space: O(n) for call stack.
class Solution2 {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (! root) return NULL;

        if (root->val > high) return trimBST(root->left, low, high);
        if (root->val < low) return trimBST(root->right, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};


// Post order traversal
// Time: O(n)
// Space: O(n) for call stack.
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (! root) return NULL;
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        if (root->val >= low && root->val <= high) {
            return root;
        } else { // remove the node, keep BST attribute.
            if (root->left && root->right) {
                // replace root with smallest node from RHS
                TreeNode* node = root->right;
                while (node->left) node = node->left;
                swap(root->val, node->val);
                root->right = trimBST(root->right, low, high);
                return root;
            } else if (root->left) {
                return root->left;
            } else if (root->right) {
                return root->right;
            } else {
                return NULL;
            }
        }
    }
};

/**
669. Trim a Binary Search Tree
Medium

Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that 
all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that 
will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.
 */
