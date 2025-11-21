// From: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/editorial/
// Time complexity: O(n). n is number of nodes.
// Space complexity: O(n)
//
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) { 
        return dfs(root).first; 
    }

    pair<TreeNode*, int> dfs(TreeNode* root) { // return: <root, depth>
        if (!root) {
            return {NULL, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.second > right.second) {
            return {left.first, left.second + 1};
        }
        if (left.second < right.second) {
            return {right.first, right.second + 1};
        }
        // left and right subtrees have the same depth and both have the deepest leaf nodes.
        return {root, left.second + 1};
    }
};

/**
1123. Lowest Common Ancestor of Deepest Leaves
Medium

Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

    The node of a binary tree is a leaf if and only if it has no children
    The depth of the root of the tree is 0. if the depth of a node is d, the depth of 
        each of its children is d + 1.
    The lowest common ancestor of a set S of nodes, is the node A with the largest depth 
        such that every node in S is in the subtree with root A.
 */
