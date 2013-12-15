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
