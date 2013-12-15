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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        if (! root) return ans;
        
        stack<TreeNode *> s;
        s.push(root);
        
        while(! s.empty()) {
            TreeNode * n = s.top();
            s.pop();
            
            ans.push_back(n->val);
            
            if (n->left) s.push(n->left);
            if (n->right) s.push(n->right);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};