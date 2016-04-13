// Works too. Iterative version with a queue.
// See: https://leetcode.com/articles/invert-binary-tree/
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (! root) return NULL;
        queue<TreeNode *> q;
        q.push(root);
        
        while (! q.empty()) {
            TreeNode * n = q.front();
            q.pop();
            
            TreeNode * tmp = n->left;
            n->left = n->right;
            n->right = tmp;
            
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode * L = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = L;
    }
};

/*
Invert Binary Tree 

Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to

     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:

    Google: 90% of our engineers use the software you wrote (Homebrew), 
    but you can’t invert a binary tree on a whiteboard so fuck off.
 */
