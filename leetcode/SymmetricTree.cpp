//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
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
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (NULL == root) return true;
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode * t1, TreeNode * t2) {
        if (t1 == NULL && t2 == NULL) return true;
        if (t1 == NULL || t2 == NULL) return false;
        
        return (t1->val == t2->val) &&
            isMirror(t1->left, t2->right) &&
            isMirror(t1->right, t2->left);
    }
};

// This works too. Uses iteration instead of recursion.
class Solution2 {
public:
    bool isSymmetric(TreeNode * root) {
        if (! root) return true;
        stack<TreeNode *> s1, s2;
        s1.push(root->left);
        s2.push(root->right);
        
        while(! s1.empty() && ! s2.empty()) {
            TreeNode * n1 = s1.top(); s1.pop();
            TreeNode * n2 = s2.top(); s2.pop();
            
            if (!n1 && !n2) continue;  // notice this.
            if (!n1 || !n2 || n1->val != n2->val) return false;
            
            s1.push(n1->left);
            s1.push(n1->right);
            s2.push(n2->right);
            s2.push(n2->left);
        }
        return true; //s1.empty() && s2.empty();
    }
};

// This works too. Same structure as Solution2, but use queue instead of stack.
class Solution3 {
public:
    bool isSymmetric(TreeNode * root) {
        if (! root) return true;
        queue<TreeNode *> s1, s2;
        s1.push(root->left);
        s2.push(root->right);
        
        while(! s1.empty() && ! s2.empty()) {
            TreeNode * n1 = s1.front(); s1.pop();
            TreeNode * n2 = s2.front(); s2.pop();
            
            if (!n1 && !n2) continue; 
            if (!n1 || !n2 || n1->val != n2->val) return false;
            
            s1.push(n1->left);
            s1.push(n1->right);
            s2.push(n2->right);
            s2.push(n2->left);
        }
        return true; 
    }
};

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
