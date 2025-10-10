class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        getSum(root, low, high, sum);
        return sum;
    }

    void getSum(TreeNode* root, int low, int high, int& sum) {
        if (!root) return;
        getSum(root->left, low, high, sum);
        if (root->val >= low && root->val <= high) sum += root->val;
        getSum(root->right, low, high, sum);
    }
};

/**
938. Range Sum of BST
[Easy]

Given the root node of a binary search tree and two integers low and high, return the sum of values 
of all nodes with a value in the inclusive range [low, high].
 */
