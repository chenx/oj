// Time: O(n), Space: O(1)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        getSum(root, NULL, sum);
        return sum;
    }

    void getSum(TreeNode* root, TreeNode* parent, int& sum) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (parent && parent->left == root) {
                sum += root->val;
            }
        }

        if (root->left) getSum(root->left, root, sum);
        if (root->right) getSum(root->right, root, sum);
    }
};

/**
404. Sum of Left Leaves

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
 */
