// Should work. Tested locally, not in lc.
// See: https://github.com/chenx/oj/blob/master/misc/BST_InorderSuccessor.cpp
class Solution3 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (! root) return NULL;

        if (p->right) { // return left most child of p->right.
            for (p = p->right; p->left; p = p->left) ;
            return p;
        }
        else {
            TreeNode * x = p;
            p = x->parent;
            while (p && x == p->right) {
                x = p;
                p = p->parent;
            }
            return p;
        }
    }
};


// Should work, not tested. Basically same as Solution.
class Solution2 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) return NULL;
        
        if (p->right != NULL) {
            for (p = p->right; p->left != NULL; p = p->left) {}
            return p;
        }
        else {
            TreeNode * suc = NULL;
            while (root != NULL) {
                if (root->val > p->val) {
                    suc = root;
                    root = root->left;
                } else if (root->val < p->val) {
                    root = root->right;
                } else {
                    break;
                }
            }
            return suc;
        }
    }
};

// This works. Tested.
// From: http://www.cnblogs.com/jcliBlogger/p/4829200.html
// Also see: https://leetcode.com/discuss/questions/oj/inorder-successor-in-bst

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p -> right) return leftMost(p -> right);
        TreeNode* suc = NULL;
        while (root) {
            if (p -> val < root -> val) {
                suc = root;
                root = root -> left;
             }
             else if (p -> val > root -> val)
                 root = root -> right; 
             else break;
         }
         return suc;
     }
private:
     TreeNode* leftMost(TreeNode* node) {
         while (node -> left) node = node -> left;
         return node;
    }
};

/**
Inorder Successor in BST
Difficulty: Medium

Problem Description:

Given a binary search tree and a node in it, find the in-order successor 
of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
 */
