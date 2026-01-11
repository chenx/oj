// Prefix sum
// From: https://leetcode.com/problems/path-sum-iii/editorial/
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<long, int> h;
        preorder(root, targetSum, count, h, 0l); // map of number of prefix sum.
        return count;
    }

    void preorder(TreeNode* node, int targetSum, 
                  int& count, unordered_map<long, int>& h, long long prefixSum) {
        if (! node) return;

        prefixSum += node->val;
        if (prefixSum == targetSum) ++ count;

        count += h[prefixSum - targetSum];
        h[prefixSum] ++;

        preorder(node->left, targetSum, count, h, prefixSum);
        preorder(node->right, targetSum, count, h, prefixSum);

        h[prefixSum] --;
    }
};

/**
437. Path Sum III
Medium

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
 */
