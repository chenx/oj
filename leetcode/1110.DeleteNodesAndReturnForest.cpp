// Preorder
// Time: O(n)
// Space: O(n) for call stack and to_delete_set.
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        set<int> to_delete_set(to_delete.begin(), to_delete.end());

        root = getForest(root, to_delete_set, result, true);
        return result;
    }

    TreeNode* getForest(TreeNode* root, set<int>& to_delete_set, vector<TreeNode*>& result, bool isRoot) {
        if (! root) return NULL;

        if (to_delete_set.contains(root->val)) {
            if (root->left) {
                getForest(root->left, to_delete_set, result, true);
            }
            if (root->right) {
                getForest(root->right, to_delete_set, result, true);
            }
            return NULL;
        } else {
            if (isRoot) result.push_back(root);
            root->left = getForest(root->left, to_delete_set, result, false);
            root->right = getForest(root->right, to_delete_set, result, false);
            return root;
        }
    }
};


/**
1110. Delete Nodes And Return Forest
Medium

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.
 */
