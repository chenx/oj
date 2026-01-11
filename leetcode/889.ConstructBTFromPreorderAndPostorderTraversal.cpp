// Approach 3: 
// From: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/editorial/
// Time: O(n)
// Space: O(n)
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex = 0;
        int postIndex = 0;
        return constructTree(preIndex, postIndex, preorder, postorder);
    }

private:
    TreeNode* constructTree(int& preIndex, int& postIndex,
                            vector<int>& preorder, vector<int>& postorder) {
        // Create a new node with the value at the current preorder index
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;  // Mark this node as created

        // Recursively construct the left subtree if the root is not the last of
        // its subtree
        if (root->val != postorder[postIndex]) {
            root->left = constructTree(preIndex, postIndex, preorder, postorder);
        }

        // Recursively construct the right subtree if the root is still not the
        // last of its subtree
        if (root->val != postorder[postIndex]) {
            root->right = constructTree(preIndex, postIndex, preorder, postorder);
        }

        // Mark this node and its subtree as fully processed
        postIndex++;

        return root;
    }
};


/**
889. Construct Binary Tree from Preorder and Postorder Traversal
Medium

Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of 
distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.
 */
