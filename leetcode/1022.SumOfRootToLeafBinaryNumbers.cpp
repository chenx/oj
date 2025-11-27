
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        getSum(root, sum, 0);
        return sum;
    }

    void getSum(TreeNode* root, int& sum, int pathSum) {
        if (root == NULL) return;

        pathSum = pathSum * 2 + root->val;
        if (! root->left && ! root->right) {
            sum += pathSum;
        }

        getSum(root->left, sum, pathSum);
        getSum(root->right, sum, pathSum);
    }
};

/**
1022. Sum of Root To Leaf Binary Numbers
Easy

You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents 
a binary number starting with the most significant bit.

    For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.
 */
