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
    TreeNode left, right, prev;
    
    public void recoverTree(TreeNode root) {
        left = null; right = null; prev = null;
        find(root);
        if (left != null && right != null) {
            int tmp = left.val;
            left.val = right.val;
            right.val = tmp;
        }
    }
    
    private void find(TreeNode root) {
        if (root == null) return;
        
        find(root.left);
        if (prev != null && prev.val > root.val) {
            if (left == null) left = prev;
            right = root;
        }
        prev = root;
        find(root.right);
    }
}


/**
Recover Binary Search Tree
Difficulty: Hard

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. 
Could you devise a constant space solution? 
 */
