/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ct = 0, val = 0;
        getKth(root, ct, k, val);
        return val;
    }
    
    void getKth(TreeNode * root, int & ct, int k, int & val) {
        if (! root) return;
        
        getKth(root->left, ct, k, val);
        ++ ct;
        if (ct == k) {
            val = root->val;
            return;
        }
        
        getKth(root->right, ct, k, val);
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
