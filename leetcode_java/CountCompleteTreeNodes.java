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
    public int countNodes(TreeNode root) {
        if (root == null) return 0;
        
        int L = 0, R = 0; // height of left and right subtrees.
        for (TreeNode n = root; n.left != null; n = n.left) { ++ L; }
        for (TreeNode n = root; n.right != null; n = n.right) { ++ R; }
        
        if (L == R) {
            return (1 << (L + 1)) - 1; // use this instead of Math.pow() to save time.
        }
        else {
            return 1 + countNodes(root.left) + countNodes(root.right);
        }
    }
}

/**
Count Complete Tree Nodes
Difficulty: Medium

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, 
is completely filled, and all nodes in the last level are as far 
left as possible. It can have between 1 and 2h nodes inclusive 
at the last level h.
 */
