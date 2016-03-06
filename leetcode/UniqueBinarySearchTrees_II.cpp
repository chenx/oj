//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// Works too. Tested. 
// Modified from Solution2 with more clean code.
class Solution3 {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode *>();
        return gen(1, n);
    }
    
    vector<TreeNode*> gen(int L, int R) {
        if (L > R) return vector<TreeNode*>(1, NULL);
        if (L == R) return vector<TreeNode*>(1, new TreeNode(L));
        
        vector<TreeNode *> ans;
        
        for (int i = L; i <= R; ++ i) {
            vector<TreeNode*> left = gen(L, i-1);
            vector<TreeNode*> right = gen(i+1, R);
            
            for (int j = 0; j < left.size(); ++ j) {
                for (int k = 0; k < right.size(); ++ k) {
                    TreeNode * root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
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
 *
 * Recursive procedure.
 * Note that trees at the same level will share some of their children.
 */
class Solution2 {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) { // This branch is needed by new version of leetcode.
            vector<TreeNode *> v;
            return v;
        }        
        return g(1, n);
    }
    
    vector<TreeNode *> g(int left, int right) {
        vector<TreeNode *> ts;
        if (left > right) {
            ts.push_back(NULL);
            return ts;
        }
        if (left == right) { // this branch can be omitted.
            ts.push_back(new TreeNode(left));
            return ts;
        }
        
        for (int i = left; i <= right; i ++) {
            vector<TreeNode *> lefts = g(left, i - 1);
            vector<TreeNode *> rights = g(i + 1, right);
            for (int j = 0; j < lefts.size(); j ++) {
                for (int k = 0; k < rights.size(); k ++) {
                    TreeNode * n = new TreeNode(i);
                    n->left = lefts[j];
                    n->right = rights[k];
                    ts.push_back(n);
                }
            }
        }
        
        return ts;
    }
};

// This generates the same tree set, but ordering is different.
// So this can't pass the test. 11/4/2014
class Solution {
public:
    vector<TreeNode *> generateTrees2(int n) {
        vector<vector<TreeNode *> > ans;
        vector<TreeNode *> t(1);

        t[0] = NULL;
        ans.push_back(t);

        t[0] = new TreeNode(1);
        ans.push_back(t);
        
        for (int i = 2; i <= n; ++ i) {
            vector<TreeNode *> tmp;
            for (int j = 0; j < i; ++ j) {
                for (int x = 0; x < ans[j].size(); ++ x) {
                    for (int y = 0; y < ans[i-1-j].size(); ++ y) {
                        TreeNode * t = new TreeNode(i);
                        t->left = ans[j][x];
                        t->right = ans[i-1-j][y];
                        tmp.push_back(t);
                    }
                }
            }
            ans.push_back(tmp);
        }
        
        return ans[n];
    }
};


/*
Problem:

Given n, generate all structurally unique BST's (binary search trees) 
that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */
