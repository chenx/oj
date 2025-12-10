/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        if (! root) return ans;
        
        stack<TreeNode *> s;
        s.push(root);
        
        while (! s.empty()) {
            TreeNode * n = s.top();
            s.pop();
            ans.push_back(n->val);
            
            if (n->right) s.push(n->right);
            if (n->left) s.push(n->left);
        }
        
        return ans;
    }
};

class Solution {
Public:
   vector<int> preorderTraversal2(TreeNode* root) {
       vector<int> result;
       pre(root, result);
       return result;
   }

   void pre(TreeNode* root, vector<int>& result) {
       if (! root) return;
       result.push_back(root->val);
       pre(root->left, result);
       pre(root->right, result);
   }
};
