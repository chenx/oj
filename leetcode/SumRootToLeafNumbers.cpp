//
// @Author: Xin Chen
// @Created on: 2/21/2013
// @Last Modified: 4/22/2013
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

// This works too.
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return getsum(root, 0);
    }
    
    int getsum(TreeNode * n, int s) {
        if (! n) return 0;
        
        if (! n->left && ! n->right) return s + n->val;
        
        int v = 10 * (s + n->val);
        return getsum(n->left, v) + getsum(n->right, v);
    }
};


// This works too, and is better.
class Solution2 {
public:
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode * root, int n) {
        if (! root) return 0;
        
        n = n*10 + root->val;
        if (! root->left && ! root->right) return n;
        else return dfs(root->left, n) + dfs(root->right, n);
    }
};


// This works too.
class Solution2 {
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL) return 0;
        
        int sum = 0;
        getSum(root, root->val, sum);
        return sum;
    }
    
    void getSum(TreeNode * root, int v, int & sum) {
        if (root->left == NULL && root->right == NULL) sum += v;

        if (root->left != NULL) getSum(root->left, v*10 + root->left->val, sum);
        if (root->right != NULL) getSum(root->right, v*10 + root->right->val, sum);
    }
};


class Solution {
public:
    int sumNumbers(TreeNode *root) {
        vector<int> nums;
        getAllNum(root, 0, nums);
        
        int sum = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
        }
        
        return sum;
    }
    
    void getAllNum(TreeNode * root, int n, vector<int> &nums) {
        if (! root) return;
        
        n = n*10 + root->val;
        
        if (root->left && root->right) {
            getAllNum(root->left, n, nums);
            getAllNum(root->right, n, nums);
        }
        else if (root->left) {
            getAllNum(root->left, n, nums);
        }
        else if (root->right) {
            getAllNum(root->right, n, nums);
        }
        else {
            nums.push_back(n);
        }
    }
};


/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. 
 */