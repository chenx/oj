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
        root->next = NULL;
        con(root, NULL);
    }
    
    // recursively search to the right side.
    TreeLinkNode * getRC(TreeLinkNode * r) {
        if (r == NULL) return NULL;
        if (r->left != NULL) return r->left;
        else if (r->right != NULL) return r->right;
        else return getRC(r->next);        
    }
    
    // r: right sibling node.
    void con(TreeLinkNode * n, TreeLinkNode * r) {
        if (n == NULL) return;
        if (n->left == NULL && n->right == NULL) return; 
        
        TreeLinkNode * rc = getRC(r);
        
        if (n->left != NULL && n->right != NULL) {
            n->left->next = n->right;
            n->right->next = rc;
            // right side should be handled first, so getRC() can work properly!
            con(n->right, rc); // NOTE: right side should be handled first!
            con(n->left, n->right);
        }
        else if (n->left != NULL) {
            n->left->next = rc;
            con(n->left, rc);
        }
        else if (n->right != NULL) {
            n->right->next = rc;
            con(n->right, rc);
        }
    }
};


// This works too, and is better!
class Solution2 {
public:
    void connect(TreeLinkNode *root) {
        conn(root, NULL);        
    }
    
    void conn(TreeLinkNode * n, TreeLinkNode * s) {
        if (! n) return;
        
        n->next = s;
        TreeLinkNode * sc = getSC(s);
        
        if (n->left && n->right) {
            conn(n->right, sc);      // NOTE: this goes first!
            conn(n->left, n->right);
        } else if (n->left) {
            conn(n->left, sc);
        } else if (n->right) {
            conn(n->right, sc);
        }
    }
    
    TreeLinkNode * getSC(TreeLinkNode * n) {
        if (! n) return NULL;
        if (n->left) return n->left;
        if (n->right) return n->right;
        return getSC(n->next);
    }
    
};

// This works too, and is the best!
class Solution3 {
public:
    void connect(TreeLinkNode *root) {
        conn(root, NULL);
    }
    
    void conn(TreeLinkNode *root, TreeLinkNode *next) {
        if (! root) return;
        root->next = next;
        
        TreeLinkNode *n = getNext(next);
        conn(root->right, n);
        conn(root->left, root->right ? root->right : n);
    }
    
    TreeLinkNode *getNext(TreeLinkNode *next) {
        if (! next) return NULL;
        if (next->left) return next->left;
        if (next->right) return next->right;
        return getNext(next->next);
    }
};

/*
Problem:

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

 */
