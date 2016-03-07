// Works. Tested. 
// Modified From: https://leetcode.com/discuss/85959/12ms-c-solution
class Solution3 {
public:
    int largestBSTSubtree(TreeNode* root) {
        int size, L, R;
        isBST(root, L, R, size);
        return size;
    }
    
    bool isBST(TreeNode * n, int &L, int &R, int & size) {
        if (n == NULL) {
            size = 0;
            return true;
        }
        
        int sizeL = 0, sizeR = 0, minL, maxL, minR, maxR;
        bool bstL = isBST(n->left, minL, maxL, sizeL);
        bool bstR = isBST(n->right, minR, maxR, sizeR);
        
        if (bstL && bstR) {
            if ( (! n->left || maxL < n->val) && 
                 (! n->right || n->val < minR) ) {
                size = 1 + sizeL + sizeR;
                
                L = n->left ? minL : n->val;
                R = n->right ? maxR : n->val;
                
                return true;
            }
        }

        size = max(sizeL, sizeR);
        return false;
    }
};

// Should work. Not tested. Similar to Solution.
class Solution2 {
public:
    int largestBSTSubtree(TreeNode* root) {
        int size;
        if (isBST(root, NULL, NULL, size)) return size;
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
    
    bool isBST(TreeNode * root, TreeNode * L, TreeNode * R, int & size) {
        if (! root) {
            size = 0;
            return true; 
        }
        
        int sizeL, sizeR;
        bool bL = isBST(root->left, L, root, sizeL),
             bR = isBST(root->right, root, R, sizeR);
        size = 1 + sizeL + sizeR;
        
        return (! L || L->val < root->val) && (! R || R->val > root->val) && bL && bR;
    }
};


// Works. Tested. O(nlogn).
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int size;
        if (isBST(root, size)) return size;
        
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
    
    bool isBST(TreeNode * root, int & size) {
        return isBST(root, INT_MIN - 1ll, INT_MAX + 1ll, size);
    }
    
    bool isBST(TreeNode * n, long long L, long long R, int & size) {
        if (n == NULL) {
            size = 0;
            return true;
        }
        
        int sizeL, sizeR;
        bool bstL = isBST(n->left, L, n->val, sizeL);
        bool bstR = isBST(n->right, n->val, R, sizeR);
        size = 1 + sizeL + sizeR;
        
        return L < n->val && n->val < R && bstL && bstR;
    }
};

/**
Largest BST Subtree My Submissions Question
Difficulty: Medium

Given a binary tree, find the largest subtree which is a 
Binary Search Tree (BST), where largest means subtree with 
largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Hint:

You can recursively use algorithm similar to 98. Validate 
Binary Search Tree at each node of the tree, which will 
result in O(nlogn) time complexity.

Follow up:
Can you figure out ways to solve it with O(n) time complexity?
 */
