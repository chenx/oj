// Recursive. Works too.
class Solution2 {
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode * prev = NULL;
        inorder(root, prev, minDiff);
        return minDiff;
    }

    // Note: use reference for prev.
    void inorder(TreeNode* root, TreeNode*& prev, int& minDiff) {
        if (!root) return;

        inorder(root->left, prev, minDiff);
        if (prev) {
            minDiff = min(minDiff, abs(prev->val - root->val));
        }
        prev = root;
        inorder(root->right, prev, minDiff);
    }
};

// Inorder traversal.
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode* n = root;
        int minDiff = INT_MAX, prev = 0;
        bool hasPrev = false;

        while (true) {
            while (n) {
                st.push(n);
                n = n->left;
            }

            if (st.empty()) break;

            n = st.top();
            st.pop();

            if (!hasPrev) {
                hasPrev = true;
            } else {
                minDiff = min(minDiff, abs(n->val - prev));
            }
            prev = n->val;

            n = n->right;
        }
        return minDiff;
    }
};

/**
530. Minimum Absolute Difference In BST

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values 
of any two different nodes in the tree.
 */
