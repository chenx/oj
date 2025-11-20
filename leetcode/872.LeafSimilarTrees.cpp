class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        getLeafSequence(root1, a);
        getLeafSequence(root2, b);
        return a == b;
    }

    void getLeafSequence(TreeNode* root, vector<int>& seq) {
        if (! root) return;
        getLeafSequence(root->left, seq);
        if (! root->left && ! root->right) {
            seq.push_back(root->val);
        }
        getLeafSequence(root->right, seq);
    }
};


/**
872. Leaf-Similar Trees
Easy

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
 */
