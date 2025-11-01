class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int total = 0, children = 0, count = 0;
        help(root, count);
        return count;
    }

    pair<int, int> help(TreeNode* root, int& count) {
        if (root == NULL)   {
            return {0, 0};
        }
   
        auto [t1, c1] = help(root->left, count);
        auto [t2, c2] = help(root->right, count);

        int total = root->val + t1 + t2;
        int children = 1 + c1 + c2;
        if (total / children == root->val) ++ count;
        return {total, children};
    }
};

/**
2265. Count Nodes Equal to Average of Subtree
Medium

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

    The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
    A subtree of root is a tree consisting of root and all of its descendants.
 */
