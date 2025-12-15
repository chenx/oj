// Get result in one traversal by recursion.
// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> levels; // <val, height>

        int height = 0;
        traverse(root, height, levels);

        for (int i = 1; i <= height; ++ i) {
            result.push_back(levels[i]);
        }
        return result;
    }

    void traverse(TreeNode* root, int& height, unordered_map<int, vector<int>>& levels) {
        if (! root) {
            height = 0;
            return;
        }

        int hl = 0, hr = 0;
        traverse(root->left, hl, levels);
        traverse(root->right, hr, levels);

        height = 1 + max(hl, hr);
        levels[height].push_back(root->val);
    }
};


// Gets result level by level in a while loop.
// Time: O(nlogn)
// Space: O(n) - row, call stack.
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        while (root != nullptr) {
            vector<int> row;
            root = getLeaves(root, row);
            result.push_back(row);
        }
        return result;
    }

    TreeNode* getLeaves(TreeNode* root, vector<int>& row) {
        if (! root) return nullptr;

        if (! root->left && ! root->right) {
            row.push_back(root->val);
            return nullptr;
        }

        root->left = getLeaves(root->left, row);
        root->right = getLeaves(root->right, row);
        return root;
    }
};


/**
366. Find Leaves of Binary Tree
Medium

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

    Collect all the leaf nodes.
    Remove all the leaf nodes.
    Repeat until the tree is empty.

 

Example 1:

Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
 */
