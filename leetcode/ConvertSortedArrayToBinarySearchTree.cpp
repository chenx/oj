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
