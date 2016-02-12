// Works. Tested. Easily to understand than Solution. Basically just recursion.
// Modified from: https://leetcode.com/discuss/69376/my-c-solution-easy-to-understand
class Solution2 {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int result = 0;
        get(root, result);
        return result;
    }
        
    void get(TreeNode *root, int &result) {
        if(root == NULL) return;

        if(same(root, root->val)) ++ result;
        get(root->left, result);
        get(root->right, result);
    }

    bool same(TreeNode* root, int val) {
        if (root == NULL) return true;
        return root->val == val && same(root->left, val) && same(root->right, val);
    }
};

// Works. Tested. From: https://leetcode.com/discuss/78200/java-recursive-simple
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        return abs(countUnivalSubtreesHelper(root));
    }

    int countUnivalSubtreesHelper(TreeNode * root) {
        if (root == NULL)
            return 0;
        int left = countUnivalSubtreesHelper(root->left);
        int right = countUnivalSubtreesHelper(root->right);
        int absv = abs(left) + abs(right);
        if ((left == 0 || (left > 0 && root->left->val == root->val))
            && (right == 0 || (right > 0 && root->right->val == root->val)))
            return absv + 1;
        else
            return -absv;
    }
};


/**
Count Univalue Subtrees
Difficulty: Medium

Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
 */
