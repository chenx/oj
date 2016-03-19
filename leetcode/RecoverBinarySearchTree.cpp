//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/26/2012
// @Last modified: 12/26/2012
//

// Works. Tested. Use in-order traversal.
class Solution3 {
public:
    void recoverTree(TreeNode* root) {
       TreeNode * L = NULL, * R = NULL, * prev = NULL;
       
       stack<TreeNode *> s;
       TreeNode * n = root;
       
       while (true) {
           while (n) {
               s.push(n);
               n = n->left;
           }
           
           if (s.empty()) {
               break;
           }
           else {
               n = s.top();
               s.pop();
               
               if (prev && prev->val > n->val) {
                   if (L == NULL) L = prev;
                   R = n;
               }
               prev = n;

               n = n->right;
           }
       }
       
       if (L && R) swap(L->val, R->val);
    }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * Good BST node n > n.left and n < n.right.
 * Find these two nodes, and swap them:
 *   1) n > n.left, but n > n.right - the larger node.
 *   2) n < n.right, but n < n.left - the smaller node.
 */
 
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// This works nicely.
// http://askmecode.wordpress.com/2012/09/21/recover-binary-search-tree/
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode * prev = NULL, * left = NULL, * right = NULL;
        find(root, prev, left, right);
        
        if (left != NULL && right != NULL) {
            swap(left->val, right->val);
        }
    }
    
    void find(TreeNode * n, TreeNode *& prev, TreeNode *& left, TreeNode *& right) {
        if (n == NULL) return;
        
        find(n->left, prev, left, right);
        if (prev != NULL && prev->val > n->val) {
            if (left == NULL) left = prev; // first one out of order.
            right = n; // update right.
        }
        prev = n;
        find(n->right, prev, left, right);
    }
    
};

// THis works too, but uglier, using pointer to pointer. instead of reference to pointer.
class Solution2 {
public:
    void recoverTree(TreeNode *root) {
        TreeNode * prev = NULL, * left = NULL, * right = NULL;
        find(root, & prev, & left, & right);
        
        if (left != NULL && right != NULL) {
            int tmp = left->val;
            left->val = right->val;
            right->val = tmp;
        }
    }
    // walk the tree in inorder.
    void find(TreeNode * n, TreeNode ** prev, TreeNode ** left, TreeNode ** right) {
        if (n == NULL) return;
        
        find(n->left, prev, left, right);
        if (*prev != NULL && (*prev)->val > n->val) {
            if (*left == NULL) *left = *prev;
            *right = n;
        }
        *prev = n;
        find(n->right, prev, left, right);
    }
    
};

/*
// This does not work.
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode * prev = NULL;
        TreeNode * left = findLeft(root, & prev);
        printf("left: %d\n", left->val);
        prev = NULL;
        TreeNode * right = findRight(root, & prev);
        printf("right: %d\n", right->val);
        
        if (left != NULL && right != NULL) {
            int tmp = left->val;
            left->val = right->val;
            right->val = tmp;
        }
    }
    
    TreeNode * findLeft(TreeNode * n, TreeNode ** prev) {
        if (n == NULL) return NULL;
        if (n->left == NULL && * prev == NULL) { *prev = n; return NULL; }
        
        TreeNode * t = findLeft(n->left, prev);
        if (t != NULL) return t;
        
        if (*prev != NULL && n->val < (*prev)->val) {
            return n;
        }
        
        return findLeft(n->right, &n);
    }
    
    TreeNode * findRight(TreeNode * n, TreeNode ** prev) {
        if (n == NULL) return NULL;
        if (n->right == NULL && * prev == NULL) { *prev = n; }
        
        //printf("findRight: n = %d, prev = %d\n", n->val, (*prev == NULL) ? -1 : (*prev)->val);
        
        TreeNode * t = findRight(n->right, &n);
        if (t != NULL) return t;
        
        if (*prev != NULL && n->val < (*prev)->val) {
            return *prev;
        }
        
        return findRight(n->left, prev);
    }
    
};
*/

int main() {
    TreeNode * n1 = new TreeNode(0);
    TreeNode * n2 = new TreeNode(1);
    n1->left = n2;
    Solution s;
    
    s.recoverTree(n1);
    
    return 0;
} 

/*
// This does not work.
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode * left = NULL, * right = NULL;
        
        find(root, &left, &right);
        
        if (left != NULL && right != NULL) {
            int tmp = left->val;
            left->val = right->val;
            right->val = tmp;
        }
    }
    
    TreeNode * getLeft(TreeNode * n, TreeNode * left) {
        if (left == NULL) return n;
        return (n->val < left->val) ? n : left;
    }

    TreeNode * getRight(TreeNode * n, TreeNode * right) {
        if (right == NULL) return n;
        return (n->val > right->val) ? n : right;
    }

    void find(TreeNode * r, TreeNode ** left, TreeNode ** right) {
        if (r == NULL) return;
        if (r->left == NULL && r->right == NULL) return;
        if (r->left == NULL) {
            find(r->right, left, right);
            if (r->val > r->right->val) {
                * right = getRight(r, * right);
                * left  = getLeft(r->right, * left);
            }
            return;
        }
        if (r->right == NULL) {
            find(r->left, left, right);
            if (r->val < r->left->val) {
                * left  = getLeft(r, * left);
                * right = getRight(r->left, * right);
            }
            return;
        }
        
        find(r->left, left, right);
        find(r->right, left, right);
        if (r->val < r->left->val) {
            * left  = getLeft(r, * left);
            * right = getRight(r->left, * right);
        }
        if (r->val > r->right->val) {
            * right = getRight(r, * right);
            * left  = getLeft(r->right, * left);
        }
    }
};
*/

/*
-- O(n) solution --     
http://basicalgos.blogspot.com/2012/09/62-recover-binary-search-tree.html
class Solution {
public:
    vector<TreeNode *> nodes;
     
    void inorderTraverse(TreeNode * root)
    {
        if (root == NULL) return;
        inorderTraverse(root->left);
        nodes.push_back(root);
        inorderTraverse(root->right);
         
    }
 
    void recoverTree(TreeNode *root) {
        nodes.clear();
         
        inorderTraverse(root);
         
        TreeNode * n1 = NULL, * n2 = NULL;
         
        for (size_t i = 0; i < nodes.size()-1; i++){
            if (nodes[i]->val > nodes[i+1]->val) { n1 = nodes[i]; break; }           
        }
        for (size_t i = nodes.size()-1; i > 0; i--){
           if (nodes[i-1]->val > nodes[i]->val) { n2 = nodes[i]; break;}  
        }
         
        int temp = n1->val;
        n1->val = n2->val;
        n2->val = temp;
    }
};
 */
