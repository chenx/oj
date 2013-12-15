//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/26/2012
// @Last modified: 12/26/2012
//
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        con(root, NULL);
    }
    
    // r: right sibling node.
    void con(TreeLinkNode * n, TreeLinkNode * r) {
        if (n == NULL) return;
        // perfect BT.
        if (n->left == NULL && n->right == NULL) return; 
        
        n->left->next = n->right;
        TreeLinkNode * rc = (r == NULL) ? NULL : r->left;
        
        n->right->next = rc;
        con(n->left, n->right);
        con(n->right, rc);
    }
};


/**
 * This works too.
 */
class Solution2 {
public:
    void connect(TreeLinkNode *root) {
        con(root, NULL);
    }
    
    void con(TreeLinkNode * r, TreeLinkNode * sibling) {
        if (r == NULL) return;
        r->next = sibling;

        con(r->left, r->right);

        if (sibling != NULL) {
            con(r->right, sibling->left);
        }
        else {
            con(r->right, NULL);
        }
    }
};


/**
 * This works too.
 */
class Solution3 {
public:
    void connect(TreeLinkNode *root) {
        root->next = NULL;
        conn(root, NULL);        
    }
    
    void conn(TreeLinkNode * n, TreeLinkNode * s) {
        if (! n) return;
        if (! n->left && ! n->right) return;
        
        n->left->next = n->right;
        conn(n->left, n->right);
        
        if (! s) {
            n->right->next = NULL;
            conn(n->right, NULL);
        }
        else {
            n->right->next = s->left;
            conn(n->right, s->left);
        }
    }
};

// This works too and is the best!
class Solution4 {
public:
    void connect(TreeLinkNode *root) {
        conn(root, NULL);        
    }
    
    void conn(TreeLinkNode * n, TreeLinkNode * s) {
        if (! n) return;
        
        n->next = s;
        conn(n->left, n->right);
        conn(n->right, (s == NULL) ? NULL : s->left);
    }
};

/*
Problem:

 Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all 
leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

 */