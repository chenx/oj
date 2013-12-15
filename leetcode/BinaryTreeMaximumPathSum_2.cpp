//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 3/19/2013
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

// This works!
// This overcomes the timeout issue of BinaryTreeMaximumPathSum.cpp, 
// by using a HNode tree with the same structure as root, in which
// "height" value h is calculated only once.
//
// The key is: to add a left/right subtree's value to current node's value,
// The left/right value must include the left/right child and does not 
// contain both! That's the need to construct a HNode tree.

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
 
struct HNode {
     int h;
     HNode *left;
     HNode *right;
     HNode(int x) : h(x), left(NULL), right(NULL) {}
};

void dumpT(TreeNode * n, int level) {
    if (! n) return;
    
    dumpT(n->right, level + 1);
    for (int i = 0; i < level; ++ i) printf(" ");
    printf("%d\n", n->val);
    dumpT(n->left, level + 1);
}
 
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        HNode * h = NULL;
        buildH(root, &h);
        
        return mSum(root, h);
    }
    
    void buildH(TreeNode * n, HNode ** h) {
        if (n == NULL) {
            *h = NULL;
            return;
        }
        
        *h = new HNode(n->val);
        if (n->left == NULL && n->right == NULL) {

        }
        else if (n->right == NULL) {
            buildH(n->left, & (*h)->left);
            (*h)->h = max(n->val, n->val + (*h)->left->h);
        }
        else if (n->left == NULL) {
            buildH(n->right, & (*h)->right);
            (*h)->h = max(n->val, n->val + (*h)->right->h);
        }
        else {
            buildH(n->left, & (*h)->left);
            buildH(n->right, & (*h)->right);
            (*h)->h = max(n->val, max(n->val + (*h)->left->h, n->val + (*h)->right->h));
        }
    }
    
    int mSum(TreeNode * n, HNode * h) {
        if (NULL == n) return 0;
        //printf("calling mSum(%d)\n", n->val);
        
        if (n->left == NULL && n->right == NULL) return n->val;
        if (n->left == NULL) return max(max(n->val, n->val + h->right->h), mSum(n->right, h->right));
        if (n->right == NULL) return max(max(n->val, n->val + h->left->h), mSum(n->left, h->left));
        
        int lh = h->left->h;
        int rh = h->right->h;
        int lm = mSum(n->left, h->left);
        int rm = mSum(n->right, h->right);
        
        int m = max(n->val, n->val + lh);
        m = max(m, n->val + rh);
        m = max(m, n->val + lh + rh);
        m = max(m, lm);
        m = max(m, rm);
        
        return m;
    }
};

//
// Code optimized from above. Slightly better. 3/19/2013
//
class Solution2 {
public:
    int maxPathSum(TreeNode *root) {
        TreeNode * h;
        buildH(root, h);
        
        return mSum(root, h);
    }
    
    int mSum(TreeNode * r, TreeNode * h) {
        if (! r) return 0;
        
        if (r->left && r->right) {
            int m1 = r->val,
                m2 = r->val + h->left->val,
                m3 = r->val + h->right->val,
                m4 = r->val + h->left->val + h->right->val,
                m5 = mSum(r->left, h->left),
                m6 = mSum(r->right, h->right);
            return max(max(max(m1, m2), m3), max(max(m4, m5), m6));
        }
        else if (r->left) {
            return max(r->val + max(0, h->left->val), mSum(r->left, h->left));
        }
        else if (r->right) {
            return max(r->val + max(0, h->right->val), mSum(r->right, h->right));
        }
        else {
            return r->val;
        }
    }
    
    void buildH(TreeNode * r, TreeNode *& h) {
        if (! r) {
            h = NULL;
            return;
        }
        
        h = new TreeNode(r->val);
        
        if (r->left && r->right) {
            buildH(r->left, h->left);
            buildH(r->right, h->right);
            h->val += max(0, max(h->left->val, h->right->val));
        }
        else if (r->left) {
            buildH(r->left, h->left);
            h->val += max(0, h->left->val);
        }
        else if (r->right) {
            buildH(r->right, h->right);
            h->val += max(0, h->right->val);
        }
    }
};

void test2() {
    TreeNode * r1 = new TreeNode(1);
    TreeNode * r2 = new TreeNode(2);
    TreeNode * r3 = new TreeNode(3);     
    r1->left = r2;
    r1->right = r3;

    Solution2 s;
    printf("%d\n", s.maxPathSum(r1));
}

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
    
    test2();
    
    return 0;
}
