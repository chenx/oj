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
    public int maxPathSum(TreeNode root) {
        maxsum = Integer.MIN_VALUE;
        getSum(root);
        return maxsum;
    }
    
    int getSum(TreeNode root) {
        if (root == null) return 0;
        int L = getSum(root.left);
        int R = getSum(root.right);
        maxsum = Math.max(maxsum, root.val + L + R);
        int ret = root.val + Math.max(L, R);
        return ret > 0 ? ret : 0;        
    }
    
    private int maxsum;
}


/**
Binary Tree Maximum Path Sum
Difficulty: Hard

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes 
from some starting node to any node in the tree along the 
parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 
 */
