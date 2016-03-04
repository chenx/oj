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
 
// Works too. Tested.
class Solution2 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode * helper(vector<int> & nums, int L, int R) {
        if (L > R) return NULL;
        
        int M = L + (R-L)/2;
        TreeNode * root = new TreeNode(nums[M]);
        
        if (L < R) {
            root->left = helper(nums, L, M-1);
            root->right = helper(nums, M+1, R);
        }
        
        return root;
    }
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return T(num, 0, num.size() - 1);
    }
    
    TreeNode * T(vector<int> &num, int left, int right) {
        if (left > right) return NULL;
        if (left == right) return new TreeNode(num[left]);
        
        int mid = (left + right) / 2;
        TreeNode * n = new TreeNode(num[mid]);
        
        n->left = T(num, left, mid - 1);
        n->right = T(num, mid + 1, right);
        
        return n;
    }
};


/**
Convert Sorted Array to Binary Search Tree
Difficulty: Medium

Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.
 */
