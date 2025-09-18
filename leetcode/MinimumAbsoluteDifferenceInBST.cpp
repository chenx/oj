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
