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
 
// Better solutions.
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (! root) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        int ct = 1;
        
        while (! q.empty()) {
            vector<int> v;
            for (; ct > 0; -- ct) {
                TreeNode * n = q.front();
                q.pop();
                v.push_back(n->val);
                
                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
            
            ans.push_back(v);
            ct = q.size();
        }
        
        return ans;
    }
};


class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (! root) return ans;
        
        queue<TreeNode *> q;
        int level_ct = 1;
        q.push(root);
        
        while (level_ct > 0) {
            int ct = 0;
            vector<int> R;
            for (int i = 0; i < level_ct; ++ i) {
                TreeNode * t = q.front();
                q.pop();
                R.push_back(t->val);
                if (t->left) {
                    q.push(t->left); ++ ct;
                }
                if (t->right) {
                    q.push(t->right); ++ ct;
                }
            }
            level_ct = ct;
            ans.push_back(R);
        }
        return ans;
    }
};
