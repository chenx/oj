//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
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
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> s;
        if (root == NULL) return v;
    
        TreeNode * n = root;
        while(1) {
            while (n != NULL) {
              s.push(n);
              n = n->left;
            }
    
            if (s.size() > 0) {
                n = s.top();
                s.pop();
                v.push_back(n->val);
                n = n->right;
            } else {
                break;
            }
        }
        return v;
    }
    
    /*       
    // recursive version. This works.
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        inorder(root, v);
        return v;
    }
    
    void inorder(TreeNode * n, vector<int> &v) {
        if (n == NULL) return;
        inorder(n->left, v);
        v.push_back(n->val);
        inorder(n->right, v);
    }
    */
};

int main() { return 0; }
