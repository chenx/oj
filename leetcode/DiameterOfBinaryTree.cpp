class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getPath(root, diameter);
        return diameter;
    }

    int getPath(TreeNode* root, int& diameter) {
        if (!root) return 0;

        int L = getPath(root->left, diameter);
        int R = getPath(root->right, diameter);

        diameter = max(diameter, L+R);
        return 1 + max(L,R);
    }
};

/**
543. Diameter of a binary tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
 */
