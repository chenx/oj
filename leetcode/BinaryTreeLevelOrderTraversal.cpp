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
 
 Use a queue. Instead of using a special marker between each level, 
 use a count to keep tract of how many nodes are on each level.
 Queue: push(), pop(), front(), back(), size(), empty().
 http://www.cplusplus.com/reference/queue/queue/
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        int level_ct, ct;
        TreeNode * n;
        vector<vector<int> > vs;
        if (NULL == root) return vs;
        
        queue<TreeNode *> q;
        q.push(root);
        level_ct = 1;
                
        while(q.size() > 0) {
            vector<int> v;
            ct = 0;
            while (level_ct > 0) {
                n = q.front();
                if (n->left != NULL) {
                    q.push(n->left);
                    ct ++;
                }
                if (n->right != NULL) {
                    q.push(n->right);
                    ct ++;
                }
                
                v.push_back(n->val);
                q.pop();
                level_ct --;
            }
            vs.push_back(v);
            
            level_ct = ct;
        }
        return vs;
    }
};
