/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int L = 0, R = 0;
        for (TreeNode * n = root->left; n != NULL; n = n->left) ++ L;
        for (TreeNode * n = root->right; n != NULL; n = n->right) ++ R;
        if (L == R) return pow(2, L+1) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

/*
Count Complete Tree Nodes 

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. It can have between 1 and 
2h nodes inclusive at the last level h.
 */
