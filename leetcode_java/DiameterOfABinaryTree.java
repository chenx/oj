class Solution2 {
    private int diameter;
    public int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        getLongestPath(root);
        return diameter;
    }

    private int getLongestPath(TreeNode root) {
        if (root == null) return 0;

        int L = getLongestPath(root.left);
        int R = getLongestPath(root.right);

        diameter = Math.max(diameter, L + R);
        return Math.max(L, R) + 1;
     }
}

class Solution {
    private int diameter;
    public int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        getLongestPath(root);
        return diameter;
    }

    private int getLongestPath(TreeNode root) {
        if (root == null) return -1;

        int L = getLongestPath(root.left);
        int R = getLongestPath(root.right);

        diameter = Math.max(diameter, L + R + 2);  // +2 to cancel out -1 of null nodes at the 2 ends.
        return Math.max(L, R) + 1;
     }
}

/**
543. Diameter of a binary tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
 */
