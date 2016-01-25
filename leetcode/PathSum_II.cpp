//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/26/2012
// @Last modified: 12/26/2012
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
 
// This works. Best solution so far.
class Solution3 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        hasPathSum(ans, path, root, sum);
        return ans;
    }
    
    void hasPathSum(vector<vector<int>> &ans, vector<int> &path, TreeNode* root, int sum) {
        if (root == NULL) return;
        
        path.push_back(root->val);
        sum -= root->val;
        
        if (root->left == NULL && root->right == NULL) {
            if (sum == 0) ans.push_back(path);
        }
        else {
            hasPathSum(ans, path, root->left, sum);
            hasPathSum(ans, path, root->right, sum);
        }            
        path.erase(path.end() - 1); // path is passed as reference to saves space.
    }
}; 
 
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > vs;
        vector<int> path;
        ps(root, sum, vs, path);
        return vs;
    }
    
    // Note: vs is passed by reference, path is passed by value (copy).
    void ps(TreeNode * n, int sum, 
            vector<vector<int> > &vs, vector<int> path) {
        if (n == NULL) return;
        
        path.push_back(n->val);
        sum -= n->val;

        if (0 == sum && n->left == NULL && n->right == NULL) {
            vs.push_back(path);
            return;
        }
        
        ps(n->left, sum, vs, path);
        ps(n->right, sum, vs, path);
    }
};


//
// This works too!
//
class Solution2 {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> path;
        hasPath(ans, path, root, sum);
        return ans;
    }
    
    void hasPath(vector<vector<int> > &ans, vector<int> path, TreeNode * root, int sum) {
        if (! root) return;
        
        if (root->left == NULL && root ->right == NULL) {
            if (root->val == sum) {
                path.push_back(root->val);
                ans.push_back(path);
                path.erase(path.end() - 1); // let path use linear space.
            }
            return;
        }
        
        path.push_back(root->val);
        hasPath(ans, path, root->left, sum - root->val);
        hasPath(ans, path, root->right, sum - root->val);

        path.erase(path.end() - 1); // let path use linear space.
    }
};


/*
Problem:
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

 */
