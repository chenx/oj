/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int kthSmallest(TreeNode root, int k) {
        ct = 0;
        TreeNode n = getKth(root, k);
        return n == null ? -1 : n.val;
    }
    
    private TreeNode getKth(TreeNode root, int k) {
        if (root == null) return null;
        
        TreeNode L = getKth(root.left, k);
        if (L != null) return L;
        
        ++ ct;
        if (ct == k) return root;
        return getKth(root.right, k);
    }
    
    private int ct;
}

/**
Kth Smallest Element in a BST
Difficulty: Medium

Given a binary search tree, write a function kthSmallest to find 
the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and 
you need to find the kth smallest frequently? How would you optimize 
the kthSmallest routine?

Hint:

    Try to utilize the property of a BST.
    What if you could modify the BST node's structure?
    The optimal runtime complexity is O(height of BST).
 */
