// BFS. Level order traversal.
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (! root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int val = 0;

        while (! q.empty()) {
            for (int i = 0, len = q.size(); i < len; ++ i) {
                TreeNode* node = q.front();
                q.pop();

                if (i == 0) val = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return val;
    }
};


/**
513. Find Bottom Left Tree Value
Medium

Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

Example 1:

Input: root = [2,1,3]
Output: 1
 */
