// This works. From: http://www.cnblogs.com/jcliBlogger/p/4829200.html
// Also see: https://leetcode.com/discuss/questions/oj/inorder-successor-in-bst

 1 class Solution {
 2 public:
 3     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
 4         if (p -> right) return leftMost(p -> right);
 5         TreeNode* suc = NULL;
 6         while (root) {
 7             if (p -> val < root -> val) {
 8                 suc = root;
 9                 root = root -> left;
10             }
11             else if (p -> val > root -> val)
12                 root = root -> right; 
13             else break;
14         }
15         return suc;
16     }
17 private:
18     TreeNode* leftMost(TreeNode* node) {
19         while (node -> left) node = node -> left;
20         return node;
21     }
22 };

/**
Inorder Successor in BST
Difficulty: Medium

Problem Description:

Given a binary search tree and a node in it, find the in-order successor 
of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
 */
