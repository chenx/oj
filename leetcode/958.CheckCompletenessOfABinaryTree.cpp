// From: https://leetcode.com/problems/check-completeness-of-a-binary-tree/editorial/
// BFS. More clear than DFS.
// Time: O(n), Space: O(1)
class Solution2 {
public:
    bool isCompleteTree(TreeNode* root) {
        if (! root) return true;

        bool nullFound = false;
        queue<TreeNode*> q;
        q.push(root);

        while (! q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                nullFound = true;
            } else {
                if (nullFound) return false;

                q.push(node->left);
                q.push(node->right);
            }
        }
    
        return true;
    }
};

// From: https://leetcode.com/problems/check-completeness-of-a-binary-tree/editorial/
// DFS.
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool dfs(TreeNode* node, int index, int n) {
        if (node == nullptr) {
            return true;
        }
        // If index assigned to current node is greater or equal to the number of nodes
        // in tree, then the given tree is not a complete binary tree.
        if (index >= n) {
            return false;
        }
        // Recursively move to left and right subtrees.
        return dfs(node->left, 2 * index + 1, n) &&
               dfs(node->right, 2 * index + 2, n);
    }

    bool isCompleteTree(TreeNode* root) {
        return dfs(root, 0, countNodes(root));
    }
};

/**
958. Check Completeness of a Binary Tree
Medium

Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in 
the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 */
