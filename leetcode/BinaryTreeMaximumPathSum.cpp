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
 http://stackoverflow.com/questions/12880110/java-the-maximum-sum-of-a-path-through-a-binary-tree
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// This works, but times out for large input.
// {-2,1,-1,8,5,7,4,9,#,3,#,0,6,5,2,#,#,#,#,3,#,7,#,0,2,1,2,#,#,#,#,6,#,0, ..
// It is slow because the "h" value of many nodes are repeatedly computed.
// The way to save time is to build a table to avoid re-calculation.
// See BinaryTreeMaximumPathSum_2.cpp for the solution.

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        return mSum(root);
    }
    
    // Called only once per node.
    // It's this complex because n->val can be negative.
    // If n->val >= 0, it's much simpler.
    int mSum(TreeNode * n) {
        if (NULL == n) return 0;
                
        if (n->left == NULL && n->right == NULL) return n->val;
        if (n->left == NULL) return max(max(n->val, n->val + h(n->right)), mSum(n->right));
        if (n->right == NULL) return max(max(n->val, n->val + h(n->left)), mSum(n->left));
        
        int lh = h(n->left);
        int rh = h(n->right);
        //printf("%d h = %d, %d h = %d\n", n->left->val, lh, n->right->val, rh);
        int lm = mSum(n->left);
        int rm = mSum(n->right);
        
        int m = max(n->val, n->val + lh);
        m = max(m, n->val + rh);
        m = max(m, n->val + lh + rh);
        m = max(m, lm);
        m = max(m, rm);
        
        return m;
    }
    
    // Repetivie called for many nodes.
    int h(TreeNode * n) {
        if (NULL == n) return 0;
        printf("calling h(%d)\n", n->val); 
        
        if (n->left == NULL && n->right == NULL) return n->val;
        if (n->left == NULL) return max(n->val, h(n->right) + n->val);
        if (n->right == NULL) return max(n->val, h(n->left) + n->val);
        return max(n->val, max(n->val + h(n->left), n->val + h(n->right)));
    }
    
    /*
    // This does NOT work.
    // addable: not branched, and used root.
    int mSum(TreeNode * n, int * addable) {
        printf("node: %d\n", n->val);
        int m;
        if (NULL == n) {
            * addable = 0;
            return INT_MIN;
        }
        
        if (n->left == NULL && n->right == NULL) {
            * addable = 1;
            printf("m = %d, addable = %d\n", n->val, * addable);
            return n->val;
        }
        
        if (n->left == NULL || n->right == NULL) {
            int a;
            int r = (n->left == NULL) ? mSum(n->right, &a) :
              mSum(n->left, &a);
            if (a) {
                m = max(r + n->val, max(r, n->val));
                if (m == r + n->val || m == n->val) * addable = 1;
                else * addable = 0;
            } else {
                m = max(r, n->val);
                if (m == n->val) * addable = 1;
                else * addable = 0;
            }
            
            printf("m = %d, addable = %d\n", m, * addable);
            return m;
        }
        
        int b1, b2;
        int l = mSum(n->left, &b1);
        int r = mSum(n->right, &b2);
        m = max(n->val, max(l, r));
        
        if (m == n->val) * addable = 1;
        else * addable = 0;

        if (b1 == 1) { 
            if (n->val + l >= m) {
                m = n->val + l;
                * addable = 1;
            }
        }
        
        if (b2 == 1) {
            if (n->val + r >= m) {
                m = n->val + r;
                * addable = 1;
            }
        }
        
        if (b1 == 1 && b2 == 1) {
            if (n->val + l + r >= m) {
                m = n->val + l + r;
                * addable = 0;
            }
        }
        
        printf("m = %d, addable = %d\n", m, * addable);
        
        return m;
        
    }
    */
};

int main() {
    TreeNode * r1 = new TreeNode(5);
    TreeNode * r2 = new TreeNode(4);
    TreeNode * r3 = new TreeNode(8);
    TreeNode * r4 = new TreeNode(11);
    TreeNode * r5 = new TreeNode(13);
    TreeNode * r6 = new TreeNode(4);
    TreeNode * r7 = new TreeNode(7);
    TreeNode * r8 = new TreeNode(2);
    TreeNode * r9 = new TreeNode(1);
    
    r1->left = r2, r1->right = r3;
    r2->left = r4;
    r3->left = r5, r3->right = r6;
    r4->left = r7, r4->right = r8;
    r6->right = r9;
    
    Solution s;
    printf("%d\n", s.maxPathSum(r1));
    
    return 0;
}
