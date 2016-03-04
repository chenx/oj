// Should work. Not tested.
class Solution3 {
public:
    int longestConsecutive(TreeNode* root) {
        int len = 0, maxLen = 0;
        helper(root, NULL, len, maxLen);
        return maxLen;
    }
    
    void helper(TreeNode * root, TreeNode * parent, int & len, int & maxLen) {
        if (root == NULL) return;
        
        if (parent == NULL) ++ len;
        else {
            if (root->val == parent->val + 1) ++ len;
            else len = 1;
        }
        
        maxLen = max(len, maxLen);
        
        helper(root->left, root, len, maxLen);
        helper(root->right, root, len, maxLen);
    }
};

// Works too. Tested.
class Solution2 {
public:
    int longestConsecutive(TreeNode* root) {
        int mlen = 0;
        getLen(NULL, root, mlen, 0);
        return mlen;
    }
    
    void getLen(TreeNode * parent, TreeNode * root, int & mlen, int len) {
        if (root == NULL) return;
        
        if (parent == NULL) {
            len = mlen = 1; // happens only for root node.
        }
        else {
            if (parent->val == root->val - 1) mlen = max(mlen, ++ len);
            else len = 1;
        }
        
        getLen(root, root->left, mlen, len);
        getLen(root, root->right, mlen, len);
    }
};

// Works. Tested.
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        int mlen = 1;
        getLen(NULL, root, mlen, 1);
        return mlen;
    }
    
    void getLen(TreeNode * parent, TreeNode * root, int & mlen, int len) {
        if (root == NULL) return;
        
        if (parent != NULL) {
            if (parent->val == root->val - 1) {
                ++ len;
                mlen = max(mlen, len);
            } else {
                len = 1;
            }
        }
        
        getLen(root, root->left, mlen, len);
        getLen(root, root->right, mlen, len);
    }
};


/**
Binary Tree Longest Consecutive Sequence My Submissions Question
Difficulty: Medium

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any 
node in the tree along the parent-child connections. The longest 
consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
 */
