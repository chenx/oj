/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        queue<TreeNode *> row;
        
        row.push(root);
        while (! row.empty()) {
            int len = row.size();
            for (int i = 0; i < len; ++ i) {
                TreeNode * n = row.front();
                row.pop();
                if (n->left != NULL) row.push(n->left);
                if (n->right != NULL) row.push(n->right);
                
                if (i == len - 1) ans.push_back(n->val);
            }
        }
        
        return ans;
    }
};

/**
Binary Tree Right Side View
Difficulty: Medium

Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4]. 
 */
