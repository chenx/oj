class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (! root) return 0;

        int count = 0, maxVal = root->val;
        countGoodNodes(root, count, maxVal);
        return count;
    }

    void countGoodNodes(TreeNode* root, int &count, int maxVal) {
        if (! root) return;

        if (root->val >= maxVal) ++ count;
        maxVal = max(maxVal, root->val);
        countGoodNodes(root->left, count, maxVal);
        countGoodNodes(root->right, count, maxVal);
    }
};


/**
1448. Count Good Nodes in Binary Tree
Medium

Given a binary tree root, a node X in the tree is named good if in the path from root to X 
there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:

Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
 */
