//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/17/2012
// @Last modified: 12/17/2012
//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree 
 * in which the depth of the two subtrees of every node never differ by more 
 * than 1. 
 */
#include <iostream> // contains definition for NULL.
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int h;
        return b(root, & h);
    }
    
    bool b(TreeNode * n, int * h) {
        if (NULL == n) {
            *h = 0;
            return true;
        }
        
        int h1, h2;
        bool b1 = b(n->left,  & h1);
        bool b2 = b(n->right, & h2);
        
        *h = 1 + max(h1, h2);
        
        return b1 && b2 && abs(h1 - h2) <= 1;
    }
};

int main() {
    return 0;
}
