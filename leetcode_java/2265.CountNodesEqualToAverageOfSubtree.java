class Solution {
    int count;

    public int averageOfSubtree(TreeNode root) {
        count = 0;
        help(root);
        return count;
    }

    Pair<Integer, Integer> help(TreeNode root) {
        if (root == null)   {
            return new Pair(0, 0);
        }
   
        Pair<Integer, Integer> p1 = help(root.left);
        Pair<Integer, Integer> p2 = help(root.right);

        int total = root.val + p1.getKey() + p2.getKey();
        int children = 1 + p1.getValue() + p2.getValue();
        if (total / children == root.val) ++ count;
        return new Pair(total, children);
    }
}

/**
2265. Count Nodes Equal to Average of Subtree
Medium

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

    The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
    A subtree of root is a tree consisting of root and all of its descendants.
 */
