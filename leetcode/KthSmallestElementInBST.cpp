/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// This works too, and should be more efficient.
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ct = 0;
        TreeNode * n = getKth(root, ct, k);
        return n ? n->val : -1;
    }
    
    TreeNode * getKth(TreeNode * root, int & ct, int k) {
        if (! root) return NULL;
        
        TreeNode * L = getKth(root->left, ct, k);
        if (L != NULL) return L;
        
        ++ ct;
        if (ct == k) {
            return root;
        }
        
        return getKth(root->right, ct, k); 
    }
};

 
// This works.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ct = 0, val = -1;
        getKth(root, ct, k, val);
        return val;
    }
    
    void getKth(TreeNode * root, int & ct, int k, int & val) {
        if (! root) return;
        
        getKth(root->left, ct, k, val);
        ++ ct;
        if (ct == k) { val = root->val; }
        else if (ct < k) { getKth(root->right, ct, k, val); }
    }
};


/*
Kth Smallest Element in a BST 

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine?

Hint:

    Try to utilize the property of a BST.
    What if you could modify the BST node's structure?
    The optimal runtime complexity is O(height of BST).

 */
