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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        getPaths(root, ans, path);
        return ans;
    }
    
    void getPaths(TreeNode * root, vector<string> &ans, string path) {
        if (! root) return;

        path = (path == "") ? to_string(root->val) : (path + "->" + to_string(root->val));
        if (! root->left && ! root->right) {
            ans.push_back(path);
            return;
        }
        if (root->left) getPaths(root->left, ans, path);
        if (root->right) getPaths(root->right, ans, path);
    }
};


/**
Binary Tree Paths
Difficulty: Easy

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]
 */
