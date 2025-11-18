class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return NULL;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (! root->left && ! root->right && root->val == target) {
            // 3. if the current node is a leaf node and its value equals target,
            // Delete the node by returning NULL to the parent, effectively disconnecting it.
            return NULL;
        }
        
        return root;  // keep it untouched otherwise
    }
};

/**
1325. Delete Leaves With a Given Value
Medium

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf 
node and has the value target, it should also be deleted (you need to continue doing that until you cannot).
 */
