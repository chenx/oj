// Tree hash (merkel tree)
// From: https://leetcode.com/problems/subtree-of-another-tree/editorial/
// Time: O(m + n)
// Space: O(m + n)
typedef unsigned long long ull;
class Solution2 {
public:
    const int MOD_1 = 1000000007;
    const int MOD_2 = 2147483647;

    // Hashing a Node
    pair<ull, ull> hashSubtreeAtNode(TreeNode* node, bool needToAdd) {
        if (node == nullptr) return {3, 7};

        auto left = hashSubtreeAtNode(node->left, needToAdd);
        auto right = hashSubtreeAtNode(node->right, needToAdd);

        auto left1 = (left.first << 5) % MOD_1;
        auto right1 = (right.first << 1) % MOD_1;
        auto left2 = (left.second << 7) % MOD_2;
        auto right2 = (right.second << 1) % MOD_2;

        pair hashpair = {(left1 + right1 + node->val) % MOD_1,
                         (left2 + right2 + node->val) % MOD_2};

        if (needToAdd) memo.push_back(hashpair);

        return hashpair;
    }

    // Vector to store hashed value of each node.
    vector<pair<ull, ull>> memo;

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        hashSubtreeAtNode(root, true);
        pair<ull, ull> s = hashSubtreeAtNode(subRoot, false);

        // Check if hash of subRoot is present in memo
        return find(memo.begin(), memo.end(), s) != memo.end();
    }
};


// Time: O(mn). m and n are number of nodes in the 2 trees.
// Space: O(m + n)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (! root) {
            return subRoot == NULL;
        }

        if (isSameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (! root && ! subRoot) return true;
        if (! root || ! subRoot) return false;
        return root->val == subRoot->val && 
            isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
};


/**
572. Subtree of Another Tree
Easy

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with 
the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's 
descendants. The tree tree could also be considered as a subtree of itself.

 

Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
 */
