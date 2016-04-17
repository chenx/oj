/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> ans;
        getPath(root, "", ans);
        return ans;
    }
    
    void getPath(TreeNode * root, string p, vector<string> & ans) {
        if (! root) return;

        if (p != "") p +="->";
        p += to_string(root->val);
        
        if (! root->left && ! root->right) ans.push_back(p);
        
        getPath(root->left, p, ans);
        getPath(root->right, p, ans);
    }
};


/**
Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.
Have you met this question in a real interview?
Example

Given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

[
  "1->2->5",
  "1->3"
]
 */
