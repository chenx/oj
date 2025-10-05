// Time complexity : O(n). The whole tree is traversed only once.
// Space complexity : O(n). The recursion goes up to a depth of n in the worst case.
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int maxLen = 0;
        getLen(root, maxLen);
        return maxLen;
    }

    vector<int> getLen(TreeNode* root, int& maxLen) {
        if (!root) return {0, 0};

        int inc = 0, dec = 0;
        if (root->left)  {
            vector<int> v = getLen(root->left, maxLen);
            if (root->val == root->left->val + 1) {
                // dec = v[1] + 1;
                inc = v[0] + 1;
            } else if (root->val == root->left->val - 1) {
                // inc = v[0] + 1;
                dec = v[1] + 1;
            }
        }

        if (root->right)  {
            vector<int> v = getLen(root->right, maxLen);
            if (root->val == root->right->val + 1) {
                // dec = max(dec, v[1] + 1);
                inc = max(inc, v[0] + 1);
            } else if (root->val == root->right->val - 1) {
                // inc = max(inc, v[0] + 1);
                dec = max(dec, v[1] + 1);
            }
        }

        maxLen = max(maxLen, inc + dec + 1);
        return {inc, dec};
    }
};

/**
549. Binary Tree Longest Consecutive Sequence II

Find the length of Longest Consecutive Path in Binary Tree. The path can be either increasing or decreasing 
i.e. [1,2,3,4] and [4,3,2,1] are both considered valid. The path can be child-parent-child or parent-child.
 */
