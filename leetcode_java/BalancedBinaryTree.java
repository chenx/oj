/**
 * Balanced Binary Tree
 * 
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which 
 * the depth of the two subtrees of every node never differ by more than 1. 
 */
 
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 
// This works.
// Compared to the C++ version, this uses tree height to carry information whether isB is true:
// if true, return non-negative int, otherwise return -1.
public class Solution {
    public boolean isBalanced(TreeNode root) {
        return isB(root) >= 0;
    }
    
    // if not balanced, return -1; else, return height.
    private int isB(TreeNode n) {
        if (n == null) {
            return 0;
        }
        
        int L = isB(n.left);
        int R = isB(n.right);
        
        if (L >= 0 && R >= 0 && Math.abs(L - R) <= 1) return 1 + Math.max(L, R);
        else return -1;
    }
}
