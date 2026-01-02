//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/17/2012
// @Last modified: 1/20/2013
//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <stack>
using namespace std;
 
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution5 {
public:
    void flatten(TreeNode* root) {
        TreeNode* tail;
        convert(root, tail);
    }

    void convert(TreeNode* root, TreeNode*& tail) {
        if (! root) {
            tail = NULL;
            return;
        }
        if (! root->left && ! root->right) {
            tail = root;
            return;
        }

        TreeNode* leftTail, *rightTail;
        convert(root->left, leftTail);
        convert(root->right, rightTail);

        if (leftTail && rightTail) {
            tail = rightTail;
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        } else if (leftTail) {
            tail = leftTail;
            root->right = root->left;
            root->left = NULL;
        } else if (rightTail) {
            tail = rightTail;
        }
    }
};

// Works. Recursive. 2025-08-21
class Solution4 {
public:
    void flatten(TreeNode* root) {
        TreeNode* tail = NULL;
        build(root, tail);
    }

    TreeNode* build(TreeNode* root, TreeNode*& tail) {
        if (!root) {
            tail = NULL;
            return NULL;
        }
        if (!root->left && !root->right) {
            tail = root;
            return root;
        }

        TreeNode* Ltail = NULL, *Rtail = NULL;
        TreeNode* L = build(root->left, Ltail);
        TreeNode* R = build(root->right, Rtail);

        root->left = NULL;

        if (L && R) {
            root->right = L;
            // Ltail->left = NULL;
            Ltail->right = R;
            tail = Rtail;
        } else if (L) {
            root->right = L;
            // Ltail->left = NULL;
            // Ltail->right = NULL;
            tail = Ltail;
        } else if (R) {
            root->right = R;
            tail = Rtail;
        }

        return root;
    }
};

// This works too. Use preorder traversal.
class Solution3 {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        
        TreeNode *tail = NULL; // there is no need to use a head pointer.
        stack<TreeNode *> s;
        s.push(root);
        
        while (! s.empty()) {
            TreeNode * n = s.top();
            s.pop();
            
            if (n->right != NULL) s.push(n->right);
            if (n->left  != NULL) s.push(n->left);
            
            if (n == root) {
                tail = n;
            } else {
                tail->right = n;
                tail = n;
            }
            tail->left = NULL;
            //tail->right = NULL; // works with or without this.
        }
        
    }
};

// This works too. 11/4/2014.
class Solution2 {
public:
    void flatten(TreeNode *root) {
        if (! root) return;
        
        TreeNode * head = NULL, * tail = NULL;
        f(root, head, tail);
        root = head;
    }
    
    void f(TreeNode * root, TreeNode *&head, TreeNode *&tail) {
        TreeNode *LH = NULL, *LT = NULL, *RH = NULL, *RT = NULL;
        if (root->left) { f(root->left, LH, LT); }
        if (root->right) { f(root->right, RH, RT); }
        
        head = tail = root;
        head->left = NULL;
        if (LH) {
            tail->right = LH;
            tail = LT;
        }
        if (RH) {
            tail->right = RH;
            tail = RT;
        }
    }
};


class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode * head = NULL, * tail = NULL;
        f(root, &head, &tail);
    }
    
    // Recursive version. This works.
    void f(TreeNode * n, TreeNode ** head, TreeNode ** tail) {
        if (n == NULL) {
           *head = NULL;
           *tail = NULL;
           return;                  
        }
         
        *head = *tail = n;
        
        TreeNode * LH, * LT, * RH, * RT, * n_right = n->right;
        
        if (n->left != NULL) {
            f(n->left, & LH, & LT);

            n->left = NULL;
            n->right = LH;
            //LH->left = n; // Can't have this! Otherwise cycle in tree.
            *tail = LT;
        }
        
        if (n_right != NULL) { 
            f(n_right, & RH, & RT);

            (*tail)->right = RH;
            //RH->left = *tail; // Can't have this! Otherwise cycle in tree.
            *tail = RT;
        }        
    }
    
    // Iterative version using preorder traversal. This works.
    void flatten_i(TreeNode *root) {
        if (NULL == root) return;
        
        stack<TreeNode *> s;
        TreeNode * n, * tail;

        s.push(root); 
        while(s.size() > 0) {
            n = s.top();
            s.pop();
                        
            if (n->right) s.push(n->right);
            if (n->left) s.push(n->left);
            
            n->left = n->right = NULL;
            if (n == root) {
                tail = n;
            }
            else {
                tail->right = n;
                tail = n;
            }
        }
    }
    
};

int main() {
    TreeNode * n1 = new TreeNode(1);
    TreeNode * n2 = new TreeNode(2);
    TreeNode * n3 = new TreeNode(3);
    n1->left = n2;
    n2->left = n3;
    
    Solution s;
    s.flatten(n1);
    
    TreeNode *ans = n1;
    while(ans) {
        printf("%d, ", ans->val);          
        ans = ans->right;
    }
    puts("");
    
    return 0;
}

